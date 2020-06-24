#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int long syscall_number;
	int parameter_number, parameter1;

	if(argc < 2)
	{
		printf("[usage]: %s <SYSCALL_NUMBER> [parameter]\n", argv[0]);
		return -1;
	}

	syscall_number = atol(argv[1]);
	parameter_number = argc - 2;

	switch(parameter_number)
	{
		case 0:
			syscall(syscall_number);
			break;
		case 1:
			parameter1 = atoi(argv[2]);
			syscall(syscall_number, parameter1);
			break;
		default:
			printf("[ERROR]: parameter number err!\n");
			break;
	}

	return 0;
}
