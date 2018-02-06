#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define PERM 0644

int main()
{
    int fd;
    char *szNewFilePath = "./newFile";

    if((fd = open(szNewFilePath, O_WRONLY | O_CREAT, PERM)) == -1) {
        fprintf(stderr, "Couldn't open... : filePath:%s", szNewFilePath);
        return 1;
    }

    printf("%s 파일이 생성되었습니다.\n", szNewFilePath);

    close(fd);
    return 0;
}

