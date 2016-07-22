#include <stdio.h>

void filecopy(FILE *ifp, FILE *ofp);

/*cat函数:连接多个文件.版本1 */
main(int argc, char *argv[])
{
    FILE *fp;

    if (argc == 1)
    {
        filecopy(stdin, stdout);
    }
    else
    {
        while (--argc > 0)
        {
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                printf("cat: can't open %s\n", *argv);
                return 1;
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    
    return 0;
}

/*filecopy函数:将文件ifp复制到文件ofp*/
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);

    return ;
}

