#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(void)
{
	char *fname = "data3";
	int fd1, fd2;

	if((fd1 = creat(fname, 0666)) < 0) {
		printf("creat error\n");
		return 1;
	}
	printf("First printf is on the screen.\n");
	fd2 = dup2(fd1,1);
	printf("Second printf is in this file.\n");
	printf("fd2:%d\n", fd2);
	return 0;
}

