#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdilb.h>
#include <string.h>
#include <unistd.h>

typedef struct _msg
{
    long mtype;
    char mtext[50];
	char name[20]; //发送者姓名	
}MSG;


int main()
{
	int id[3]={10,11,12};
	char name[3][20]={"tom","lucy","bob"};
	MSG msg;
	key_t key = ftok(".",2001);
	int msgqid=msgget(key,IPC_CREAT);
	if(msgqid<0)
	{
		perror("msgqid");
		return 1;
	}
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork");
		return 1;
	}
	else if(pid == 0)
	{
		char chatname[20];
		printf("please input name:");
		fgets(chatname,20,stdin);
		strtok(chatname,"\n");
		strcpy(msg.name,chatname);
	}
	return 0;
}
