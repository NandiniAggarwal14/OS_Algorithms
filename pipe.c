#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int x;
	int fd[2];
	char re[100], wr[]="Good morning";
	pid_t p;
	if((x=pipe(fd))==-1)
		printf("\nPipe cannot be created");
	else
	{
		p=fork();
		if(p<0)
			printf("\nFork unsuccessful");
		else if(p>0)
		{
			close(fd[0]);
			printf("\nParent process writes\n");
			write(fd[1], wr, sizeof(wr));
			close(fd[1]);
			printf("\nParent finished writing\n");
		}
		else
		{
			close(fd[1]);
			printf("\nChild process reads\n");
			read(fd[0], re, sizeof(re));
			close(fd[0]);
			printf("\nChild read: %s", re);
			printf("\nChild finished reading\n");
		}
	}
	return 0;
}
