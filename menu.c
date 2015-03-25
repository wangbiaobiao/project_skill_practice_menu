#include<stdio.h>

#define CMD_NUMBER 256

typedef struct DataNode
{
	char* cmd;
	char* desc;
	int (*handler)();
	struct DataNode *next;
}tDataNode;

int help()
{
	printf("this is help cmd\n");
	return 0;
}

int quit()
{
	printf("this is quit cmd\n");
	return 0;
}

static tDataNode head[] =
{
	{"help", "this is help cmd", help, &head[1]},
	{"version","menu program v1.0", NULL, NULL}

};

int main()
{
	char cmd[CMD_NUMBER];
	tDataNode *p = head;
	printf("please input your cmd\n");
	while(1)
	{
		tDataNode *p = head;
		scanf("%s",cmd);
		while(p != NULL)
		{
			if(strcmp(p->cmd,cmd) == 0)
			{
				if(p->handler != NULL)
				{
					p->handler();
				}
				break;
			}
			p = p->next;
			if(p == NULL)
			{
				printf("this isn't a cmd\n");
			}
		}
	}
	return 0;
}
