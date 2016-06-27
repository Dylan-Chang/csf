#include "apue.h"
#include <sys/wait.h>

int
main(void)
{
	char	buf[MAXLINE];
	pit_t	pid;
	int	status;



