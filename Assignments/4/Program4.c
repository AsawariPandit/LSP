#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
	DIR *dp = NULL;
	struct dirent *dobj = NULL;
	int fdWrite = 0,fdRead = 0, Ret = 0;
	char path[20]={'\0'};
	char Buffer[10]={'\0'};
	if(argc != 2)
	{
		printf("Insufficient argument\n");
		return -1;
	}
	fdWrite = open("Demo.txt",O_WRONLY);
	dp = opendir(argv[1]);
	if(fdWrite == -1 || dp == NULL)
	{
		printf("Unable to open required file / directory\n");
		return -1;
	}
	while((dobj = readdir(dp)) != NULL)
	{
		sprintf(path, "%s/%s",argv[1],dobj->d_name);
		fdRead = open(path, O_RDONLY);
		Ret = read(fdRead,Buffer,10);
		printf("Buffer %s",Buffer);
		write(fdWrite, Buffer, Ret);
		close(fdRead);
	}
	
	close(fdWrite);	
	closedir(dp);
	
	return 0;
}
