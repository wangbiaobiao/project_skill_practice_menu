#include <stdio.h>
#include "linklist.h"

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
