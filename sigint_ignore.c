#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
	/* code */
	struct sigaction st;
	st.sa_handler = SIG_IGN;
	st.sa_flags = 0;
	sigaction(SIGINT,&st,NULL);
	sleep(5);
	printf("\nIgnore\n");

	st.sa_handler = SIG_DFL;
	sigaction(SIGINT,&st,NULL);
	sleep(5);
	printf("Default\n");
	return 0;
}