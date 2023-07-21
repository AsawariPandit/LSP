#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/dir.h>
int main(int argc, char *argv[])
{
	DIR *d = NULL;
	struct dirent *dobj = NULL;

	if(argc != 2)
	{
		printf("Insufficient arguments\n");
	}

	d = opendir(argv[1]);
	if(d == NULL)
	{
		printf("Can't open directory %s\n",argv[1]);
		return -1;
	}
	while((dobj = readdir(d)) != NULL)
	{
		printf("%s\n",dobj->d_name);
	}
	closedir(d);
	return 0;

}
