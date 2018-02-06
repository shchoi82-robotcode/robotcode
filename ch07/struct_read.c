#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

typedef struct TAG_GPIOCTL_DATA{
    int pinNo;
    int onTime;
    int offTime;
    int repeat;
}GPIOCTL_DATA;

int main(void)
{
    char *fname = "gpio_data";
    int fd;
    const int DATA_SIZE = sizeof(GPIOCTL_DATA);

    GPIOCTL_DATA data;

    if((fd = open(fname, O_RDONLY)) == -1){
        fprintf(stderr, "open error\n");
        return 1;
    }
    if(read(fd, &data, DATA_SIZE) != DATA_SIZE){
        fprintf(stderr, "read error\n");
        return 1;
    }
    printf("pinNo:%d\n", data.pinNo);
    printf("onTime:%d\n", data.onTime);
    printf("offTime:%d\n", data.offTime);
    printf("repeat:%d\n", data.repeat);

    return 0;
}

