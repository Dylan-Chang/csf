
#define ALLOCSIZE 10000 /*���ÿռ��С*/
static char allocbuf[ALLOCSIZE]; /*allocʹ�õĴ洢��*/
static char *allocp = allocbuf;  /*��һ������λ��*/

/*����ָ��n���ַ���ָ��*/
char *alloc(int n)
{
    /*���㹻�Ŀ��пռ�*/
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;/*���ط���ǰ��ָ��p*/
    }
    else /*���пռ䲻��*/
    {
        return 0;
    }
}

/*�ͷ�pָ��Ĵ洢��*/
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
