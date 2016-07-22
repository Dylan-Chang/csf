
typedef long Align; /*��װlong���ͱ߽����*/

union header        /*���ͷ��*/
{
    struct
    {
        union header *ptr; /*���п������е���һ��*/
        unsigned size;     /*����Ĵ�С*/
    }s;
    Align x;               /*ǿ�ƿ�Ķ���*/
}��

typedef union header Header;

static Header base;       /*�ӿ�����ʼ*/
static Header *freep = NULL; /*��������ĳ�ʼָ��*/

char *sbrk(int);

#define NALLOC 1024

/*��ϵͳ�������Ĵ洢�ռ�*/
Header *morecore(unsigned nu)
{
    char *cp;
    Header *up;

    if (nu < NALLOC)
        nu = NALLOC;
    cp = sbrk(nu * sizeof(Header));
    if (cp == (char *)-1) /*û�пռ�*/
        return NULL;
    up = (Header *)cp;
    up->s.size = nu;
    free((void *)(up+1));
    return freep;
}


/*ͨ�ô洢���亯��*/
void *malloc(unsigned nbytes)
{
    Header *p, *prevp;
    unsigned nunits;

    nunits = (nbytes+sizeof(Header)-1)/sizeof(Header)+1;
    /*û�п�������*/
    if ((prevp = freep) == NULL)
    {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }

    for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr)
    {
       
        if (p->s.size >= nunits) /*�㹻��*/
        {
            if (p->s.size == nunits)/*����*/
            {
                prevp->s.ptr = p->s.ptr;
            }
            else                    /*����ĩβ����*/
            {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *)(p+1);
        }

        if (p == freep)        /*�ջ��Ŀ�������*/
            if ((p = morecore(nunits)) == NULL)
                return NULL;   /*û��ʣ��Ĵ洢�ռ�*/
    }
}

/*����ap������п�������*/
void free(void *ap)
{
    Header *bp, *p;

    bp = (Header *)ap - 1; /*ָ���ͷ*/
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    {
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;         /*���ͷŵĿ�������Ŀ�ͷ��ĩβ*/
    }

    if (bp + bp->s.size == p->s.ptr)   /*����һ���ڿ�ϲ�*/
    {
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    }
    else
    {
        bp->s.ptr = p->s.ptr;
    }

    if (p + p->s.size == bp)          /*����һ���ڿ�ϲ�*/
    {
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    }
    else
    {
        p->s.ptr = bp;
    }

    freep = p;
}