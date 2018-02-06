#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(void)
{
    char *fname = "lseek_ex1.c";
    int fd;
    off_t fsize;

    if((fd = open(fname, O_RDONLY)) == -1){
        printf("open error\n");
        return 1;
    }

    fsize = lseek(fd, 0, SEEK_END);
    printf("The size of <%s> is %lu bytes.\n", fname, fsize);
    return 0;
}

