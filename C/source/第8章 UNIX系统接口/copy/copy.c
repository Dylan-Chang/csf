#include "syscalls.h"

/*�����븴�Ƶ����*/
main()
{
    char buf[BUFSIZ];

    int n;
    while ((n = read(0, buf, BUFSIZ))>0)
        write(1, buf, n);

    return 0;
}
