#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>

/*
 * system call number
 */
#define SYSCALL_0		436
#define SYSCALL_INT1	437
#define SYSCALL_INT2	438
#define SYSCALL_STR1	439

void syscall_0(void)
{
	syscall(SYSCALL_0);
}

void syscall_int1(void)
{
	int p1 = 0x01;

	syscall(SYSCALL_INT1, p1);
}

void syscall_int2(void)
{
	int p1 = 0x01;
	int p2 = 0x02;

	syscall(SYSCALL_INT2, p1, p2);
}

void syscall_str1(void)
{
	char p1[64] = "hello world";

	syscall(SYSCALL_STR1, p1);
	printf("kernel to user: %s\n", p1);
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("[usage]: %s <TYPE>\n", argv[0]);
		return -1;
	}

	if(!strcmp(argv[1], "int1"))
		syscall_int1();
	else if(!strcmp(argv[1], "int2"))
		syscall_int2();
	else if(!strcmp(argv[1], "str1"))
		syscall_str1();
	else
		syscall_0();

	return 0;
}
