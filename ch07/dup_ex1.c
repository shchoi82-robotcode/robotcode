#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	char *fname = "data2";
	int fd1, fd2, cnt;
	char buf[30];

	if((fd1 = open(fname, O_RDONLY)) == -1){
		printf("open error/n");
		return 1;
	}

	fd2 = dup(fd1);
	cnt = read(fd1, buf, 4);
	buf[cnt] = '\0';
	printf("fd1's printf : %s\n", buf);
	printf("current file offeset:%ld\n", lseek(fd1, 0, SEEK_CUR));

	cnt = read(fd2, buf, 4);
	buf[cnt] = '\0';
	printf("fd2's printf : %s\n", buf);

	return 0;
}



