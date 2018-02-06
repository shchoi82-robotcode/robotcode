#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;
    ssize_t nRead;
    char *szFilePath = "./test2.txt";
    char buf[1024];
    if((fd = open(szFilePath, O_RDONLY)) == -1){
        printf("Couldn't open.. : FilePath=%s\n", szFilePath);
        return 1;
    }
    nRead = read(fd, buf, sizeof(buf));
    if(nRead == -1){
        printf("Couldn't read...");
        return 1;
    }
    printf("nRead = %u\n", nRead);
    close(fd);
    return 0;
}

