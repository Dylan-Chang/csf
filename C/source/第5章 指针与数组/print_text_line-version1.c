#include <stdio.h>
#include <string.h>

#define MAXLINES 5000    /*�������������ı�����*/
char *lineptr[MAXLINES]; /*ָ���ı��е�ָ������*/

#define MAXLEN 1000      /*ÿ�������ı��е���󳤶�*/

#define ALLOCSIZE 10000  /*���ÿռ��С*/
static char allocbuf[ALLOCSIZE]; /*allocʹ�õĴ洢��*/
static char *allocp = allocbuf;  /*��һ������λ��*/


char *alloc(int n);
int getline(char s[], int lim);
int readlines(char *lineptr[],  int nlines);
void writelines(char *lineptr[], int nlines);
void swap(char *v[], int i, int j);
void qsort(char *lineptr[], int left, int right);



/*��������ı��н�������*/
int main()
{
    int nlines;  /*��ȡ����������Ŀ*/

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}


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


/*getline����: ��һ�ж��뵽s�в������䳤��*/
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


/*��ȡ������*/
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
            line[len-1] = '\0';/*ɾ�����з�*/
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}


/*д�����*/
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}


void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


/*������˳���v[left] ... v[right]��������*/
void qsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right)
        return ;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1;i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}


