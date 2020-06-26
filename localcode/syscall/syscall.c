#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int long syscalln;
	int parametern, p1, p2;

	if(argc < 2)
	{
		printf("[usage]: %s <SYSCALL_NUMBER> [parameter]\n", argv[0]);
		return -1;
	}

	syscalln = atol(argv[1]);
	parametern = argc - 2;

	switch(parametern)
	{
		case 0:
			syscall(syscalln);
			break;
		case 1:
			p1 = atoi(argv[2]);
			syscall(syscalln, p1);
			break;
		case 2:
			p1 = atoi(argv[2]);
			p2 = atoi(argv[3]);
			syscall(syscalln, p1, p2);
			break;
		default:
			printf("[ERROR]: parameter number err!\n");
			break;
	}

	return 0;
}
