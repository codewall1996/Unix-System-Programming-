#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/msg.h>

struct cl_msg{
	long type;
	char cmd[7];
	int num;
};

struct sr_msg{
	long type;
	int res;
};

int main(){
	int ip_msgid=msgget(0x1234,IPC_CREAT|0666);
	int op_msgid=msgget(0x6789,IPC_CREAT|0666);
	struct cl_msg clm;
	struct sr_msg srm;
	clm.type=getpid();
	clm.cmd[0]='c';
	clm.cmd[1]='u';
	clm.cmd[2]='b';
	clm.cmd[3]='e';
	clm.cmd[4]='\0';
	clm.num=4;
	msgsnd(ip_msgid,&clm,sizeof(clm)-sizeof(long),0);
	msgrcv(op_msgid,&srm,sizeof(srm)-sizeof(long),getpid(),0);
	printf("%s of %d is %d\n",clm.cmd,clm.num,srm.res);
	return 0;
}