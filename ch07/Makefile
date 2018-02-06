EXAMPLES = open_ex1.out \
		   open_ex2.out \
		   open_ex3.out \
		   open_ex4.out \
		   stdfd.out \
		   read_ex1.out \
		   read_ex2.out \
		   mycp.out \
		   lseek_ex1.out \
		   lseek_ex2.out \
		   struct_write.out \
		   struct_read.out \
		   dup_ex1.out \
		   dup_ex2.out \
		   fcntl_ex1.out \

all : $(EXAMPLES)

CFLAGS = -Wall -W

%.out : %.c
	gcc $(CFLAGS) $< -o $@ 


clean : 
	-rm $(EXAMPLES)

