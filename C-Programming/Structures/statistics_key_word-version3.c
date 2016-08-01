#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100  
char buf[BUFSIZE];   /*����ungetch�����Ļ�����*/
int bufp = 0;        /*buf����һ������λ��*/

struct tnode
{
    char *word;            /*ָ�򵥴ʵ�ָ��*/
    int count;             /*���ʳ��ֵĴ���*/
    struct tnode *left;    /*���ӽڵ�*/
    struct tnode *right;   /*���ӽڵ�*/
};

int getch(void);
void ungetch(int c);
int getword(char *, int);
struct tnode *talloc(void);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);

/*ͳ��������C���Թؼ��ֵĳ��ִ���*/
main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
            root = addtree(root, word);
    }

    treeprint(root);
    return 0;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/*�������ж�ȡ��һ�����ʻ��ַ�*/
int getword(char *word, int lim)
{
    int c;
    char *w = word;

    while (isspace(c = getch()))
    {
        ;
    }

    if (c != EOF)
        *w++ = c;
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++)
    {
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    
    return word[0];
}

/*��p��λ�û�p���·�����һ��w�ڵ�*/
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL)
    {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {
        p->count++;
    }
    else if (cond < 0)
    {
        p->left = addtree(p->left, w);
    }
    else
    {
        p->right = addtree(p->right, w);
    }

    return p;
}

/*����һ��tnode*/
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

/*�����ӡ��p*/
void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

