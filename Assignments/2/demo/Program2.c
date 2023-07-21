#include<stdio.h>
#include<fcntl.h>
#define MAX_SIZE 1024
int main(int argc, char *argv[])
{
	int fd = 0, Ret =0;
	char WBuffer[] = "Hello Asawari";
	char Buffer[MAX_SIZE];
	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	fd = open(argv[1], O_WRONLY);
	if(fd == -1)
	{
		printf("Unable to open file %s",argv[1]);
		return -1;
	}
	write(fd, WBuffer, sizeof(WBuffer));
	/*	
	while((Ret = read(fd, &Buffer, sizeof(Buffer))) != 0)
	{
		write(1, Buffer, sizeof(Buffer));
		memset(Buffer,0,sizeof(Buffer));
	}*/
	close(fd);
	return 0;
}
