#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE  100  


enum {NAME, PARENS, BRACKETS};
           
int tokentype;               /*���һ���Ǻŵ�����*/ 
char token[MAXTOKEN];        /*���һ���Ǻ��ַ���*/
char name[MAXTOKEN];         /*��ʶ������*/
char datatype[MAXTOKEN];     /*��������Ϊchar��int��*/
char out[1000];              /*�����*/
char buf[BUFSIZE];           /*����ungetch�����Ļ�����*/
int bufp = 0;                /*buf����һ������λ��*/

void dcl(void);
void dirdcl(void);
int getch(void);
void ungetch(int c);
int gettoken(void); 


/*������ת��Ϊ����������*/
main()
{
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF)
    {
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
        {
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*')
            {
                sprintf(temp, "(*%s)", out);
                strcpy(out, temp);
            }
            else if (type == NAME)
            {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            }
            else
            {
                printf("invalid input at %s\n", token);
            }
        }
        printf("%s\n", out);
    }

    return 0;
}

/*��һ�������������﷨����*/
void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*';)
        ns++;/*ͳ���ַ�*�ĸ���*/

    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
        
}

/*����һ��ֱ������*/
void dirdcl(void)
{
    int type;

    if (tokentype == '(')  /*��ʽΪ(dcl)*/
    {
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    }
    else if (tokentype == NAME) /*������*/
        strcpy(name, token);
    else
        printf("error: expected name or (dcl)\n");

    while ((type = gettoken()) == PARENS || type == BRACKETS)
    {
        if (type == PARENS)
            strcat(out, " function returning");
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
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


/*������һ�����*/
int gettoken(void)
{
    int c;
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']';)
        {
            ;
        }
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch());)
        {
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
    {
        return tokentype = c;
    }

}
