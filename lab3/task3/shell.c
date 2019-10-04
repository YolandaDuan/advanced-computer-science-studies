
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
char command[100];
//int i = 0;
do
{
printf("myshell > ");
scanf("%s",command);

//command == ls
if(strcmp(command, "ls") == 0)
{
	int pid = fork();
	if(pid == 0)
	{
		execl("/bin/ls", "ls", (char *) NULL);

	}
	else{
	wait(NULL);}

}else if(strcmp(command, "pstree")== 0)
{
	int pid = fork();
	if(pid == 0)
	{
		execl("/usr/bin/pstree", "pstree", (char *) NULL);
	}
	 else{
        wait(NULL);}

}else if(strcmp (command, "htop")== 0)
{
	int pid = fork();
	if(pid == 0)
	{
		execl("/usr/bin/htop", "htop", (char *) NULL);
	}
	 else{
        wait(NULL);}

}else if(strcmp(command, "ifconfig")==0)
{
	int pid = fork();
	if(pid == 0)
	{
		execl("/sbin/ifconfig", "ifconfig", (char *) NULL);
	}
	 else{
        wait(NULL);}

}else if(strcmp(command,"quit")==0)
{
	printf("quitting...\n");
}
else
{
	printf("Command Unknown\n");
}
}while(strcmp(command,"quit")!=0);

}
