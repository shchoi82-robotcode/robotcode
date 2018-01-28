#include <stdio.h>
#include <pigpiod_if2.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#define MAX7219_REG_DECODEMODE  0x9
#define MAX7219_REG_INTENSITY   0xA
#define MAX7219_REG_SCANLIMIT   0xB
#define MAX7219_REG_SHUTDOWN    0xC
#define MAX7219_REG_DISPLAYTEST 0xF
#define SPI_CHANNEL             0
#define SPI_CLOCK               10e6

int pi;
int fd;
void spi(uint8_t reg, uint8_t val) {
    uint8_t buf[2];
    buf[0] = reg;
    buf[1] = val;
    spi_write(pi, fd, buf, 2);
    usleep(20);
}

void clear()
{
    uint8_t buf[2];
    for(int i = 0; i < 8; i++){
        buf[0] = i+1;
        buf[1] = 0;
        spi(buf[0], buf[1]);
    }
}

void dot(int row, int col)
{
    uint8_t buf[2];
    buf[0] = row;
    buf[1] = 1 << (8-col);
    spi(buf[0], buf[1]);

}
int main(void)
{

    uint8_t buf[2];
    int i;

    if((pi = pigpio_start(NULL, NULL)) < 0){
        fprintf(stderr, "pigpiod_start error\n");
        return 1;
    }

    if((fd = spi_open(pi, SPI_CHANNEL, SPI_CLOCK, 0)) < 0){
        fprintf(stderr, "spi_open error\n");
        return 2;
    }

    spi(MAX7219_REG_DECODEMODE,0x00);
    spi(MAX7219_REG_SCANLIMIT,0x07);
    spi(MAX7219_REG_INTENSITY,0x01);
    spi(MAX7219_REG_SHUTDOWN,0x01);

    uint8_t mat[8] = {  0b00000000,
                        0b01100110,
                        0b11111111,
                        0b11111111,
                        0b11111111,
                        0b01111110,
                        0b00111100,
                        0b00011000};

    clear();

    for(i = 0; i < 8; i++){
        buf[0] = i+1;
        buf[1] = mat[i];
        spi(buf[0], buf[1]);
        time_sleep(0.1);
    }
    spi_close(pi, fd);
    pigpio_stop(pi);

    return 0;
}


