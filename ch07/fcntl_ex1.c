#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main(void)
{
	char *fname = "data";
	int fd;
	int flag;

	if((fd = open(fname, O_RDWR | O_APPEND)) < 0) {
		printf("open error\n");
		return 1;
	}
	flag = fcntl(fd, F_GETFL, 0);

	switch(flag & O_ACCMODE){
		case O_RDONLY:
			printf("O_RDONLY flag is set.\n");
			break;
		case O_WRONLY:
			printf("O_WRONLY flag is set.\n");
			break;
		case O_RDWR:
			printf("O_RDWR flag is set.\n");
			break;
		default:
			printf("unknown accemode");
			break;
	}

	if (flag & O_APPEND)
		printf("fd: O_APPEND flag is set. \n");
	else
		printf("fd: O_APPEND flag is NOT set. \n");

	flag = fcntl(fd, F_GETFD, 0);
	if (flag & FD_CLOEXEC)
		printf("fd: FD_CLOEXEC flag is set. \n");
	else
		printf("fd: FD_CLOEXEC flag is NOT set. \n");

	fcntl(fd, F_SETFD, FD_CLOEXEC);
	flag = fcntl(fd, F_GETFD, 0);
	if (flag & FD_CLOEXEC)
		printf("fd: FD_CLOEXEC flag is set. \n");
	else
		printf("fd: FD_CLOEXEC flag is NOT set. \n");

	return 0;
}

