#include<stdio.h>
#include<dirent.h>
#include<string.h>
int main(int argc, char *argv[])
{
	DIR *d = NULL;
	struct dirent *dobj;
	int ret = -1;
	if(argc != 3)
	{
		printf("Insufficient arguments.\n");
		return -1;
	}
	d = opendir(argv[1]);
	while((dobj = readdir(d)) != NULL)
	{
		if((ret = strcmp(dobj->d_name, argv[2])) == 0)
		{
			break;
		}
	}
	if(ret == 0)
	{
		printf("File %s is present in directory %s\n",argv[2],argv[1]);
	}
	else
	{
		printf("File %s is not present in directory %s\n",argv[2],argv[1]);
	}
	closedir(d);
	return 0;
}
