#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
int main(int argc, char *argv[])
{
	DIR *d = NULL;
	struct dirent *dobj = NULL;
	char oldname[50];
	char newname[50];

	if(argc != 3)
	{
		printf("Insufficient arguments\n");
	}
	d = opendir(argv[1]);
	if(d == NULL)
	{
		printf("Unable to open directory\n");
		return -1;
	}
	while((dobj = readdir(d)) != NULL)
	{
		sprintf(oldname,"%s/%s",argv[1],dobj->d_name);
		sprintf(newname,"%s/%s",argv[2],dobj->d_name);

		rename(oldname, newname);
	}
	closedir(d);
	return 0;

}
