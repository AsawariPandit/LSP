#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#define MAXREADSIZE 1024
int main()
{
	char FileName[256] = {'\0'};
	int fd = 0;
	int Mode = 0, Ret = 0;
	char Buffer[MAXREADSIZE]={'\0'};
	int BytesToRead = 0;
	struct stat sobj;
	printf("Enter the file name that you want to open\n");
	scanf("%s",FileName);
	
	printf("Enter the number of bytes that you want to read from file %s ",FileName);
	scanf("%d",&BytesToRead);

	fd = open(FileName, O_RDONLY);
	
	if(fd == -1)
	{
		printf("Unable to open file : %s\n",FileName);
		return -1;
	}
	
	Ret = read(fd, &Buffer, BytesToRead);
	if(Ret == 0)
	{
		printf("Cant read data in file %s",FileName);
		return -1;
	}	
	printf("Data from file \n%s",Buffer);
	close(fd);
	return 0;
}
