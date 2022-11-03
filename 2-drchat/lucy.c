#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

typedef struct _msg
{
	long mtype;
	char mtext[50];
	char name[20]; //接收者姓名
    char sendname[20];//发送者姓名
} MSG;

int main()
{
	int id[3] = {10, 11, 12};
	char name[3][20] = {"lucy", "tom", "bob"};
	char buf[120] = {0};
	MSG msg;
	key_t key = ftok(".", 2001);
	int msgqid = msgget(key, IPC_CREAT | 0666);
	if (msgqid < 0)
	{
		perror("msgqid");
		return 1;
	}
	pid_t pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return 1;
	}
	else if (pid == 0)
	{
		while (1)
		{
			printf("I'm lucy!\n");
			printf("please input name:");
			fgets(buf, 120, stdin);
			buf[strlen(buf) - 1] = '\0';
			//退出模块
			if (strcmp(buf, "exit") == 0)
            {
                kill(getppid(), 9);
                kill(getpid(), 9);
            }
			strcpy(msg.sendname,"lucy");
			strcpy(msg.name, buf);
			for (int i = 0; i < 3; i++)
			{
				if (strcmp(msg.name, name[i]) == 0)
				{
					msg.mtype = id[i];
					break;
				}
			}
			printf("请输入信息：");
			memset(buf, 0, 120);
			fgets(buf, 120, stdin);
			buf[strlen(buf) - 1] = '\0';
			strcpy(msg.mtext, buf);
			msgsnd(msgqid, &msg, sizeof(msg) - sizeof(long), 0);
		}
	}
	else
	{
		while (1)
		{
			msgrcv(msgqid, &msg, sizeof(msg) - sizeof(long), 10, 0);
			if (strlen(msg.mtext) != 0)
			{
				system("clear");
				printf("接收到%s发送的信息: %s\n", msg.sendname, msg.mtext);
			}
			printf("please input name:");
			fflush(stdout);
		}
	}
	msgctl(msgqid, IPC_RMID, NULL);
	return 0;
}
