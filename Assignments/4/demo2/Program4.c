#include<stdio.h>
#include<dirent.h>
int main(int argc, char *argv[])
{
	DIR *dp = NULL;
	struct dirent *dobj = NULL;
	if(argc != 2)
	{
		printf("Insufficient argument\n");
		return -1;
	}
	dp = opendir(argv[1]);
	if(dp == NULL)
	{
		printf("Unable to open directory\n");
		return -1;
	}
	while((dobj = readdir(dp)) != NULL)
	{
		printf("filename : %s",dobj->d_name);
	}
	closedir(dp);
	
	return 0;
}
