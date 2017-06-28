#include <stdio.h>
#include <string.h>

#define MAXLINES 5000    /*进行排序的最大文本行数*/
char *lineptr[MAXLINES]; /*指向文本行的指针数组*/

#define MAXLEN 1000      /*每个输入文本行的最大长度*/

#define ALLOCSIZE 10000  /*可用空间大小*/
static char allocbuf[ALLOCSIZE]; /*alloc使用的存储区*/
static char *allocp = allocbuf;  /*下一个空闲位置*/


char *alloc(int n);
int getline(char s[], int lim);
int readlines(char *lineptr[],  int nlines);
void writelines(char *lineptr[], int nlines);
void swap(void *v[], int i, int j);
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

//(int (*)(void *, void*))

/*对输入的文本行进行排序*/
int main(int argc, char *argv[])
{
    int nlines;        /*读取的输入行数目*/
    int numeric = 0;   /*若进行数值排序，则numeric的值为1*/

    if (argc < 1 && strcmp(argv[1], "-n") == 0)
    {
        numeric = 1;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort((void **)lineptr, 0, nlines - 1, (numeric ? (int (*)(void *, void*))numcmp : (int (*)(void *, void*))strcmp));
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}


/*返回指向n个字符的指针*/
char *alloc(int n)
{
    /*有足够的空闲空间*/
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;/*返回分配前的指针p*/
    }
    else /*空闲空间不够*/
    {
        return 0;
    }
}


/*getline函数: 将一行读入到s中并返回其长度*/
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}


/*读取输入行*/
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;

    while ((len = getline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
        {
            return -1;
        }
        else
        {
            line[len-1] = '\0';/*删除换行符*/
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}


/*写输出行*/
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}


void swap(void *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


/*按递增顺序对v[left] ... v[right]进行排序*/
void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;

    if (left >= right)
        return ;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1;i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);
}

/*按数值顺序比较字符串s1和s2*/
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}
