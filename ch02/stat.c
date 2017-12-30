#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	struct stat buf;
	if(stat(argv[1], &buf) == -1){
		printf("stat error\n");
		return 1;
	}
	printf("file onwer user  : %d\n", buf.st_uid);
	printf("file owner group : %d\n", buf.st_gid);
	return 0;
}

