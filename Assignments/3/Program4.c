#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
int main(int argc, char *argv[])
{
	DIR *d = NULL;
	struct dirent *dobj;
	struct stat sobj;
	char path[50];
	int ret = -1;
	if(argc != 2)
	{
		printf("Insufficient arguments.\n");
		return -1;
	}
	d = opendir(argv[1]);
	while((dobj = readdir(d)) != NULL)
	{	
		sprintf(path,"%s/%s",argv[1],dobj->d_name);
		stat(path,&sobj);	
		if(sobj.st_size == 0)
		{
			remove(path);
			printf("Removed file %s\n",path);	
		}
	}
	
	closedir(d);
	return 0;
}
