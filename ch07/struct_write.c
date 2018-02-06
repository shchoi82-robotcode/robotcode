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

    printf("pinNo:");scanf("%d", &data.pinNo);
    printf("onTime:");  scanf("%d", &data.onTime);
    printf("offTime:"); scanf("%d", &data.offTime);
    printf("repeat:");  scanf("%d", &data.repeat);

    if((fd = open(fname, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1){
        fprintf(stderr, "open error\n");
        return 1;
    }
    if(write(fd, &data, DATA_SIZE) != DATA_SIZE){
        fprintf(stderr, "write error\n");
        return 1;
    }

    return 0;
}


