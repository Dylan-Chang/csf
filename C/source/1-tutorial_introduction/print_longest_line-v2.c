#include <stdio.h>

#define MAXLINE 100  /*����������е���󳤶�*/

int max;  /*ĿǰΪֹ���ֵ���еĳ���*/
char line[MAXLINE];     /*��ǰ��������*/
char longest[MAXLINE];  /*���ڱ��������*/

int getline(void);
void copy(void);

/*��ӡ���������*/
main()
{
    int len;  /*��ǰ�г���*/
    
    max = 0;
    while ((len = getline()) > 0)
    {
        if (len > max)
        {
            max = len;
            copy();
        }
    }

    if (max > 0)
    { 
        printf("%s", longest);
    }
    
    return 0;
}

/*getline����: ��һ�ж��뵽s�в������䳤��*/
int getline(void)
{
    int c, i;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

/*copy����: ��from���Ƶ�to������ٶ�to�㹻��*/
void copy(void)
{
    int i;
    
    i = 0;
    while ((longest[i] = line[i]) != '\0')
    {
        ++i;
    }
}


