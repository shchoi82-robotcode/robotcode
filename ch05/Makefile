EXAMPLES =	am2302.out \
			hcsr04_pigpio.out \
			hcsr04_pigpiod_if2_async.out \
			mcp3208.out \
			mcp3208_all.out \
			mcp3208_pigpio.out \
			mpu6050.out \

all : $(EXAMPLES)

am2302.out : am2302.c
	gcc -Wall -W -pthread -lrt -lpigpiod_if2 -Wno-unused-parameter $^ -o $@

hcsr04_pigpio.out : hcsr04_pigpio.c
	gcc -Wall -W -pthread -lrt -lpigpio -Wno-unused-parameter $^ -o $@

hcsr04_pigpiod_if2_async.out : hcsr04_pigpiod_if2_async.c
	gcc -Wall -W -pthread -lrt -lpigpiod_if2 -Wno-unused-parameter $^ -o $@

mcp3208.out : mcp3208.c
	gcc -Wall -W -pthread -lrt -lpigpiod_if2 -Wno-unused-parameter $^ -o $@

mcp3208_all.out : mcp3208_all.c
	gcc -Wall -W -pthread -lrt -lpigpiod_if2 -Wno-unused-parameter $^ -o $@

mcp3208_pigpio.out : mcp3208_pigpio.c
	gcc -Wall -W -pthread -lrt -lpigpio -Wno-unused-parameter $^ -o $@

mpu6050.out : mpu6050.c
	gcc -Wall -W -pthread -lrt -lpigpiod_if2 -Wno-unused-parameter $^ -o $@


clean : 
	rm $(EXAMPLES)
