#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#define PERM 0644
#define BUFFSIZE 1024

int main(int argc, char* argv[])
{
    int nSrcFd,nDstFd;
    ssize_t nRead = 0;
    ssize_t nWrite = 0;
    char buf[BUFFSIZE] = {0};
    char* szSrcFilePath = argv[1];
    char* szDstFilePath = argv[2];

    if((nSrcFd = open(szSrcFilePath, O_RDONLY)) == -1) {
        printf("Couldn't open : filePath=%s", szSrcFilePath);
        return 1;
    }

    if((nDstFd = creat(szDstFilePath, PERM)) == -1) {
        printf("Couldn't creat : filePath=%s", szDstFilePath);
        return 2;
    }

    while((nRead = read(nSrcFd, buf, 1024)) > 0) {
        if(write(nDstFd,buf,nRead) < nRead) {
            printf("Couldn't write");
            close(nDstFd);
            close(nSrcFd);
            return 3;
        }
        nWrite += nRead;
        memset(buf,0,sizeof buf);
    }

    close(nDstFd);
    close(nSrcFd);

    if(nRead == -1) {
        printf("Couldn't read");
        return 5;
    }

    printf("nWrite = %d", nWrite);
    return 0;
}

