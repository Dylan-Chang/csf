

struct nlist
{
    struct nlist *next; /*链表中下一个表项*/
    char *name;
    char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];/*指针表*/

/*为字符串s生成散列值*/
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
    {
        hashval = *s + 31 * hashval;
    }

    return hashval % HASHSIZE;
}

/*在hashtab中查找s*/
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;   /*找到s*/
    return NULL;         /*未找到s*/
}

/*将(name, defn)加入到hashtab中*/
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    /*未找到*/
    if ((np = lookup(name)) == NULL)
    {
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;

        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else /*已存在*/
    {
        free((void*)np->defn);/*释放前一个defn*/
    }

    if ((np->defn = strdup(defn)) == NULL)
    {
        return NULL;
    }

    return np;
}