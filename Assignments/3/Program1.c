#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(int argc, char *argv[])
{
	char Buffer1[50],Buffer[50];
	int fd1 = 0, fd2  = 0;
	int ret =0;
	if(argc != 3)
	{
		printf("Insufficient argument.\n");
		return -1;
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2],O_RDWR);
	
	if(fd1 == -1 || fd2 == -1)
	{
		printf("Unable to open file.\n");
		return -1;
	}
	while((ret = read(fd1, Buffer1, sizeof(Buffer1))) != 0)
	{
		write(fd2,Buffer1,ret);
		memset(Buffer1,0,ret);
	}
	close(fd1);
	close(fd2);	
	return 0;
}
