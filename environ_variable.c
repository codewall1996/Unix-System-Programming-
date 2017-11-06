#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int print_environ(char* name){
	extern char**environ;
	printf("%s\n", name);
	for(char **p = environ;*p != NULL;p++)
		printf("%s\n", *p);
	return 0;
}

int main(int argc, char const *argv[])
{
	if(fork())
	{
		//setenv("OLDPWD","Indiana Jones",1); 
		print_environ("parent");
		return 0;
	}
	else{
		setenv("OLDPWD","Indiana Jones",1);
		print_environ("child");
		return 0;	
	}
}