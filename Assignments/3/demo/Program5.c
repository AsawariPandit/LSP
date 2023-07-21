#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
int main(int argc, char *argv[])
{
	DIR *d = NULL;
	struct dirent *dobj;
	struct stat sobj;
	char path[25]={'\0'};
	int iMax = 0;
	char FileName[256];
	
	d = opendir(argv[1]);
	if(d == NULL)
	{
		printf("Unable to open directory %s",argv[1]);
		return -1;
	}	
	while((dobj = readdir(d)) != NULL)
	{
		sprintf(path,"%s/%s",argv[1],dobj->d_name);
		stat(path, &sobj);
		if(S_ISREG(sobj.st_mode) && sobj.st_size > iMax)
		{
			iMax = sobj.st_size;
			strcpy(dobj->d_name, FileName);
		}
	}	
	printf("Largest File in directory %s is %s size %d.",argv[1],FileName,iMax);
	closedir(d);
	return 0;
}
