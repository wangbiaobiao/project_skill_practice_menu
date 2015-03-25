#include<stdio.h>
#include "linklist.h"
#define CMD_NUMBER 256


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
	tDataNode *p;
	while(1)
	{
		printf("please input your cmd >");
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
