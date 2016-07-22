#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *ifp, FILE *ofp);

/*cat����:���Ӷ���ļ�.�汾2 */
main(int argc, char *argv[])
{
    FILE *fp;
    char *prog = argv[0];   /*���³�����������������*/

    /*���û�������в��������Ʊ�׼����*/
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
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }

    if (ferror(stdout))
    {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    
    exit(0);
}

/*filecopy����:���ļ�ifp���Ƶ��ļ�ofp*/
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);

    return ;
}

