#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
    char *fname = "shared";
    int fd;
    off_t curOffset;
    long i;

    if((fd = open(fname, O_WRONLY | O_APPEND)) == -1){
        printf("open error\n");
        return 1;
    }

    for(i = 0 ; i < 100000 ; i++){
        if(write(fd, "0", 1) != 1)
            exit(1);
        printf("%ld\r", i);
    }
    return 0;
}

