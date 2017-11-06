#include<stdio.h>
#include<unistd.h>

int main(){
	char name[50];
	symlink("test","symlink");
	int ret=readlink("symlink",name,50);
	name[ret]='\0';
	printf("File name is: %s no of char is : %d\n",name,ret);
	return 0;
}

