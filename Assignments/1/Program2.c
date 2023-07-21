#include<stdio.h>
#include<fcntl.h>
int main()
{
	char FileName[256] = {'\0'};
	int fd = 0;
	int Mode = 0;

	printf("Enter the file name that you want to open\n");
	scanf("%s",FileName);
	printf("Enter File Mode : \n Press \n 1 : READ Only \n 2 : WRITE Only \n 3 : READ / WRITE \n 4 : CREATE \n");
	scanf("%d",&Mode);
	
	switch(Mode)
	{
		case 1:
			Mode = O_RDONLY;
			break;
		case 2: 
			Mode = O_WRONLY;
			break;
		case 3: 
			Mode = O_RDWR;
			break;
		case 4: 
			Mode = O_CREAT;
			break;
		default: 
			Mode = O_RDONLY;
			break;
	};

	fd = open(FileName, Mode);
	
	if(fd == -1)
	{
		printf("Unable to open file : %s\n",FileName);
		return -1;
	}
	printf("File %s is successfully opened with FileDescriptor %d\n",FileName,fd);
	return 0;
}
