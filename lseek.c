#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

//compile this as gcc one.c -D _GNU_SOURCE


int main(){
	int fd=open("test.txt",O_RDWR|O_TRUNC,0777);
	if(fd==-1){
		perror("Open error:\n");
	}

	printf("Opened the file with O_TRUNC flag and 0777 mode\n");

	int w=write(fd,"abcdefghij",10);
	if(w!=10){
		perror("write error\n");
	}
	printf("Wrote abcdefghij at starting\n");

	int x = lseek(fd,30,2);
	if(x!=40){
		perror("seek error \n");
	}else{
		printf("can seek beyond end pointer\n hole of size 30 created\n");
	}

	
	int y=write(fd,"ABCDEFGHIJ",10);
	if(y!=10){
		perror("Write error\n");
	}
	printf("Wrote ABCDEFGHIJ at ending\n");

	lseek(fd,0,0);
	int n=lseek(fd,0,SEEK_HOLE);
	printf("seeked first hole from position 0. current position at %d\n",n);

	lseek(fd,0,0);
	int m=lseek(fd,0,SEEK_DATA);
	printf("seeked  first data from position 0. current position at %d\n",m);

	int a=lseek(fd,-30,0);
	if(a<0){
		perror("cant access to the left of starting\n");
	}
	return 0;
}
