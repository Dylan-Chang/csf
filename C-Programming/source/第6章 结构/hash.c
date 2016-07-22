

struct nlist
{
    struct nlist *next; /*��������һ������*/
    char *name;
    char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];/*ָ���*/

/*Ϊ�ַ���s����ɢ��ֵ*/
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
    {
        hashval = *s + 31 * hashval;
    }

    return hashval % HASHSIZE;
}

/*��hashtab�в���s*/
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;   /*�ҵ�s*/
    return NULL;         /*δ�ҵ�s*/
}

/*��(name, defn)���뵽hashtab��*/
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    /*δ�ҵ�*/
    if ((np = lookup(name)) == NULL)
    {
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;

        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else /*�Ѵ���*/
    {
        free((void*)np->defn);/*�ͷ�ǰһ��defn*/
    }

    if ((np->defn = strdup(defn)) == NULL)
    {
        return NULL;
    }

    return np;
}