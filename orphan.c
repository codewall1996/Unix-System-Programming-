#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	/* code */
	if (fork())
	{
		printf("%d\n",getpid());
	}
	else{
		printf("Original Parent : %d\n",getpid());
		sleep(20);
		printf("New Parent Parent : %d\n",getppid());
	}
	return 0;
}	