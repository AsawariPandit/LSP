#include<stdio.h>
#include<fcntl.h>
#define MAX_SIZE 1024
int main(int argc, char *argv[])
{
	int fd = 0, Ret =0;
	char Buffer[MAX_SIZE]={'\0'};
	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file %s",argv[1]);
		return -1;
	}
	while((Ret = read(fd, &Buffer, sizeof(Buffer))) != 0)
	{
		write(1, Buffer, sizeof(Buffer));
		memset(Buffer,0,sizeof(Buffer));
	}
	close(fd);
	return 0;
}
