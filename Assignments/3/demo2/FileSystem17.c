#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
int main(int argc, char *argv[])
{
	DIR *d = NULL;
	struct dirent *dobj = NULL;
	char FileName[30]={'\0'};

	if(argc != 3)
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
		if((strcmp(argv[2],dobj->d_name))==0)
		{
			printf("File %s is present in dir %s\n",argv[2],argv[1]);
			break;
		}
		else
		{
			printf("File %s is not present in dir %s\n",argv[2],argv[1]);
		}
		//sprintf(FileName,"%s",dobj->d_name);
		//printf("%s\n",FileName);
	}
	closedir(d);
	return 0;

}
