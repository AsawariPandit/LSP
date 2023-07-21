#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/dir.h>
#include<sys/stat.h>
int main(int argc, char *argv[])
{
	DIR *d = NULL;
	struct dirent *dobj = NULL;
	struct stat sobj;
	char path[20]={'\0'};

	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}

	d = opendir(argv[1]);
	if(d == NULL)
	{
		printf("Can't open directory %s\n",argv[1]);
		return -1;
	}
	while((dobj = readdir(d)) != NULL)
	{
		sprintf(path,"%s/%s",argv[1],dobj->d_name);
		stat(path,&sobj);
		printf("Filename : %s Type : %d \n",path,sobj.st_mode);
	}
	closedir(d);
	return 0;

}
