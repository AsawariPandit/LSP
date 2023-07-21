#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
typedef int BOOL;
#define TRUE 1
#define FALSE 0
BOOL CheckEvenOdd(int iNo)
{
	if(( iNo % 2 ) == 0)
	{
		return TRUE;
	}
	return FALSE;
}
int main()
{
	BOOL Ret = 0, No = 0;
	scanf("%d",&No);
	Ret = CheckEvenOdd(No);
	if(Ret == TRUE)
	{
		printf("%d is a even number.",No);
	}
	else
	{
		printf("%d is a odd number.",No);
	}
	return 0;
}

// gcc Program1.c 
// ./a.out < input.txt > output.txt

/*
int main(int argc, char *argv[])
{
	BOOL Ret= 0, iNo = 0;
	char No[20]={'\0'};
	while(read(0, No, sizeof(No)) != 0)
	{
		//iNo = atoi(No);
		scanf("%d",&iNo);
		Ret = CheckEvenOdd(iNo);
		if(Ret == TRUE)
		{
			printf("%d is a even number.",iNo);
		}
		else
		{
			printf("%d is a odd number.",iNo);
		}
		memset(No, 0, sizeof(No));
	}
	return 0;
}
*/
