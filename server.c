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

int square(int num){
	return num*num;
}

int cube(int num){
	return num*num*num;
}

int main(){
	int ip_msgid=msgget(0x1234,IPC_CREAT|0666);
	int op_msgid=msgget(0x6789,IPC_CREAT|0666);
	struct cl_msg clm;
	struct sr_msg srm;
	while(1){
		msgrcv(ip_msgid,&clm,sizeof(clm)-sizeof(long),0,0);
		if(clm.cmd[0]=='s'){
			srm.type=clm.type;
			srm.res=square(clm.num);
			msgsnd(op_msgid,&srm,sizeof(srm)-sizeof(long),0);	
		}
		if(clm.cmd[0]=='c'){
			srm.type=clm.type;
			srm.res=cube(clm.num);
			msgsnd(op_msgid,&srm,sizeof(srm)-sizeof(long),0);	
		}
	}
	return 0;
}