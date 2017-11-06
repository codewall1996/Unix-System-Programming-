#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	if( fork() ){
			sleep(20);
			printf("%d\n",getpid());
	}
	else{
			printf("In child\nFinished process\n");
	}
	return 0;
}