#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{
    int fd;
    long offset;

    if((fd = open("./data", O_WRONLY | O_APPEND)) == -1){
        fprintf(stderr, "open error\n");
        return 1;
    }
    offset = lseek(fd, 0, SEEK_CUR);
    printf("before write offset:%ld\n", offset);
    if(write(fd, "7777", 4) != 4){
        fprintf(stderr, "write error\n");
        return 1;
    }
    offset = lseek(fd, 0, SEEK_CUR);
    printf("after write offset:%ld\n", offset);
    offset = lseek(fd, 0, SEEK_END);
    printf("file size:%ld\n", offset);
    close(fd);
    return 0;
}

