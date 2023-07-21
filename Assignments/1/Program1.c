#include<stdio.h>
#include<fcntl.h>
int main()
{
	char FileName[256] = {'\0'};
	int fd = 0;
	printf("Enter the file name that you want to open\n");
	scanf("%s",FileName);

	fd = open(FileName, O_RDONLY);
	
	if(fd == -1)
	{
		printf("Unable to open file : %s\n",FileName);
		return -1;
	}
	printf("File %s is successfully opened with FileDescriptor %d\n",FileName,fd);
	return 0;
}
