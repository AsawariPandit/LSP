#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#define MAXREADSIZE 1024
int main()
{
	char FileName[256] = {'\0'};
	int Mode = 0, Ret = 0;
	
	printf("Enter the file name that you want to open\n");
	scanf("%s",FileName);

	printf("Enter File Mode : \n Press \n 1 : READ \n 2 : WRITE \n 3 : Execute\n");
	scanf("%d",&Mode);
	
	switch(Mode)
	{
		case 1:
			Mode = R_OK;
			break;
		case 2:
			Mode = W_OK;
			break;
		case 3: 
			Mode = X_OK;
			break;
	};	

	Ret = access(FileName, Mode);
	if(Ret == -1)
	{
		printf("You cant access file %s in specified mode.\n",FileName);
	}
	else
	{
		printf("You can access file %s in specified mode.\n",FileName);
	}
	return 0;
}
