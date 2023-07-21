#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fd=0;

	printf("Usage : Nam_of_Executable Name_Of_File_Mode_Of_Open\n");
	if(argc != 2)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}
	fd = creat(argv[1],0777);
	if(fd==-1)
	{
		printf("unable to open file\n");
		return -1;
	}
	else
	{
		printf("File is successfully created with fd %d\n",fd);
	}
	
	return 0;
}
