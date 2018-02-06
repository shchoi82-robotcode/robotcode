#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd;
    char *szFilePath = "./newFile";

    if((fd = open(szFilePath, O_RDONLY)) == -1) {
        fprintf(stderr, "Couldn't open.. : filePath=%s\n", szFilePath);
        return 1;
    }

    printf("%s 파일을 열었습니다\n", szFilePath);
    printf("fild descriptor:%d\n", fd);

    close(fd);
    return 0;
}

