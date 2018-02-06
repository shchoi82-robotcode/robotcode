#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	char *fname = "data";
	int fd1, fd2, cnt;
	char buf[30];

	fd1 = open(fname, O_RDONLY);
	fd2 = open(fname, O_RDONLY);
	if(fd1 == -1 || fd2 == -1) {
		printf("open error\n");
		return 1;
	}

	cnt = read(fd1, buf, 12);
	buf[cnt] = '\0';
	printf("fd1's first printf : %s\n", buf);

	lseek(fd1, 1, SEEK_CUR);
	cnt = read(fd1, buf, 12);
	buf[cnt] = '\0';
	printf("fd1's second printf : %s\n", buf);

	cnt = read(fd2, buf, 12);
	buf[cnt] = '\0';
	printf("fd2's first printf : %s\n", buf);

	lseek(fd2, 1, SEEK_CUR);
	cnt = read(fd2, buf, 12);
	buf[cnt] = '\0';
	printf("fd2's second printf : %s\n", buf);

	return 0;
}

