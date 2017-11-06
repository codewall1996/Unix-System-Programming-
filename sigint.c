#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

void fun1(int signal_no){
	
	printf("\nThe signal for which the handler is changed is %d\n",signal_no );
	struct sigaction st;
	st.sa_handler = SIG_DFL;
	st.sa_flags = 0;
	sigaction(SIGINT,&st,NULL);
}

int main(int argc, char const *argv[])
{
	/* code */
	struct sigaction st;
	st.sa_handler = fun1;
	st.sa_flags = 0;
	sigaction(SIGINT,&st,NULL);
	sleep(5);
	printf("I'm in the main function\n");
	sleep(5);
	return 0;
}