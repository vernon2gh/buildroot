#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("[usage]: %s <SYSCALL_NUMBER>\n", argv[0]);
		return -1;
	}

	syscall(atol(argv[1]));

	return 0;
}
