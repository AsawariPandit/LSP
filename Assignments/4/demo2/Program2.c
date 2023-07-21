#include<stdio.h>
#include<sys/stat.h>
int main(int argc, char *argv[])
{
	int dd = 0;
	if(argc != 2)
	{
		printf("Insufficient argument\n");
		return -1;
	}
	dd = mkdir(argv[1], 0777);
	if(dd == -1)
	{
		printf("Unable to create directory dd : %d.",dd);
		return -1;
	}
	else
	{	
		printf("Directory created - dd : %d.\n",dd);
	}
	return 0;
}
