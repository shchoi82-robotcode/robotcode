#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *args[])
{
	int i;

	for(i = 0 ; i < argc ; i++)
	//	for(i = 0 ; args[i] != NULL ; i++)
		printf("args[%d]: %s\n", i, args[i]);
	exit(0);
}


