#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	/* code */
	int fd=open("test.txt",O_RDWR,0777);
	printf("Original : %d\n",fd);
	if (fd == -1)
	{
		perror("Error opening file");
	}

	int fd_dup = dup2(fd,fd_dup);
	printf("Duplicate using dup2 : %d\n",fd_dup);

	close(1);
	int fd_dup_fcntl = fcntl(fd,F_DUPFD,1);
	printf("Duplicate using fcntl : %d\n",fd_dup_fcntl );

	close(2);
	int fd_dup_fcntl_error = fcntl(fd,F_DUPFD,2);
	perror("I'm sorry");
	return 0;
}