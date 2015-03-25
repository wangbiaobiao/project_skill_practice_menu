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

tDataNode * FindCmd(tDataNode * head, char * cmd)
{
	if(head == NULL || cmd == NULL)
	{
		return NULL;
	}
	tDataNode *p = head;
	while(p != NULL)
	{
		if(strcmp(p->cmd, cmd) == 0)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

int main()
{
	char cmd[CMD_NUMBER];
	tDataNode *p;
	printf("please input your cmd\n");
	while(1)
	{
		scanf("%s",cmd);
		p = FindCmd(head, cmd);
		if(p == NULL)
		{
			printf("this isn't a cmd\n");
			continue;
		}
		if(p->handler != NULL)
		{
			p->handler();
		}
	}
	return 0;
}
