#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define BLOCKSIZE 1024
int main(int argc, char *argv[])
{	
	int fdSrc = 0, fdDest = 0;
	char Buffer[BLOCKSIZE] = {'\0'};
	int Ret = 0;
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	fdSrc = open(argv[1],O_RDONLY);
	if(fdSrc == -1)
	{
		printf("Unable to open source file\n");
		return -1;
	}
	fdDest =  creat(argv[2], 0777);
	if(fdDest == -1)
	{
		printf("unable to create destinatiion file\n");
		close(fdSrc);
		return -1;	
	}
	while((Ret = read(fdSrc, Buffer, sizeof(Buffer)))!= 0)
	{
		write(fdDest, Buffer, Ret);
		memset(Buffer,0,sizeof(Buffer));
	}
	close(fdSrc);
	close(fdDest);
	return 0;
}
