#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>


void custom_sig(int sig_no)
{
}

int main(int argc, char const *argv[])
{
	signal(SIGUSR1,custom_sig);
	int i,j;
	int count = 0;
	pid_t pid;

	pid = fork();

	if(pid != 0)
		for(i=100;i >= 20; i=i-20){
			printf("%d : ",getpid());
			for(j=0;j<10;j++)
				printf("%d ",i-j);
			printf("\n");
			sleep(1);
			kill(pid,SIGUSR1);
			pause();
		}
	else		
		for(i = 81; i > 0; i = i - 20){
           pause();
           printf("%d : ", getpid());
           for(j=0;j<10;j++)
                 printf("%d ",i+j);
              
		   printf("\n");
		   sleep(1);
		   kill(getppid(),SIGUSR1);	
		}
	return 0;
}