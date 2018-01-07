EXAMPLES =	direct_reg_access.out \
			hello_pigpio.out \
			led_pigpio.out \
			led_pigpiod_if2.out \
			switchbtn_ex1.out \
			switchbtn_ex2.out \
			switchbtn_ex3.out \
			switchbtn_ex4.out \
			switchbtn_ex5.out \
			switchbtn_ex6.out \

CFLAGS = -Wall -W

all : $(EXAMPLES)  

direct_reg_access.out : direct_reg_access.c
	gcc $(CFLAGS) $^ -o $(OUTPUT_PATH)$@

hello_pigpio.out : hello_pigpio.c
	gcc $(CFLAGS) -lpigpio -lpthread -lrt $^ -o $@

led_pigpio.out : led_pigpio.c
	gcc $(CFLAGS) -lpigpio -lpthread -lrt $^ -o $@

led_pigpiod_if2.out : led_pigpiod_if2.c
	gcc $(CFLAGS) -lpigpiod_if2 -lpthread -lrt $^ -o $@

switchbtn_ex1.out : switchbtn_ex1.c
	gcc $(CFLAGS) -lpigpiod_if2 -lpthread -lrt $^ -o $@

switchbtn_ex2.out : switchbtn_ex2.c
	gcc $(CFLAGS) -lpigpiod_if2 -lpthread -lrt $^ -o $@

switchbtn_ex3.out : switchbtn_ex3.c
	gcc $(CFLAGS) -lpigpiod_if2 -lpthread -lrt $^ -o $@

switchbtn_ex4.out : switchbtn_ex4.c
	gcc $(CFLAGS) -Wno-unused-parameter -lpigpiod_if2 -lpthread -lrt $^ -o $@

switchbtn_ex5.out : switchbtn_ex5.c
	gcc $(CFLAGS) -Wno-unused-parameter -lpigpiod_if2 -lpthread -lrt $^ -o $@

switchbtn_ex6.out : switchbtn_ex6.c
	gcc $(CFLAGS) -Wno-unused-parameter -lpigpiod_if2 -lpthread -lrt $^ -o $@

clean :
	rm $(EXAMPLES)
