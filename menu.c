#include<stdio.h>
void help()
{
	printf("this is help cmd\n");
}
void quit()
{
	printf("this is quit cmd\n");
}
int main()
{
	char cmd[256];
	while(1)
	{
		scanf("%s",cmd);
		if(strcmp(cmd,"help") == 0)
		{
			help();
		}
		else if(strcmp(cmd, "quit") == 0)
		{
			quit();
		}
		else
		{
			printf("this is not a cmd\n");
		}
	}
	return 0;

}
