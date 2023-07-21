#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	char FileName[256] = {'\0'};
	int fd = 0;
	int Mode = 0, Ret = 0;;
	struct stat sobj;
	printf("Enter the file name that you want to open\n");
	scanf("%s",FileName);
	
	fd = open(FileName, Mode);
	fd = open(FileName, Mode);
	
	if(fd == -1)
	{
		printf("Unable to open file : %s\n",FileName);
		return -1;
	}
	printf("File %s is successfully opened with FileDescriptor %d\n",FileName,fd);
	
	printf("------------------------------------------------------------------\n");
	
	Ret = fstat(fd, &sobj);
	if(Ret == 0)
	{
		printf("File information\n");
		printf("------------------------------------------------------------------\n");
		printf("INode No : %d\n",(int)sobj.st_ino);
		printf("Dev Id : %d\n", (int)sobj.st_dev);
		printf("Mode : %d\n",(int)sobj.st_mode);
		printf("Links : %d\n", (int)sobj.st_nlink);
		printf("uid : %d\n", sobj.st_uid);
		printf("fid : %d\n", sobj.st_gid);
	}
	else
	{
		printf("Cant find information about file %s", FileName);
	}
	close(fd);
	return 0;
}
