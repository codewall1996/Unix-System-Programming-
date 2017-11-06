#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>


int pid;

void fun1(int signal_no){
	printf("Pid of the process handling the handler is %d\n",getpid());
}

int main(int argc, char const *argv[])
{
	
	struct sigaction st;

	sigemptyset(&st.sa_mask);
	st.sa_handler = fun1;
	st.sa_flags = 0;
	sigaction(SIGALRM,&st,NULL);
	
	alarm(5);
	if((pid=fork()) == 0){
		printf("Child pid %d\n",getpid());
		sleep(5);
	}
	else{
		printf("Parent pid %d\n",getpid());
		sleep(5);	
	}
	return 0;
}