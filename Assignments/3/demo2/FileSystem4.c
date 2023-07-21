#include<stdio.h>
int main(int argc, char *argv[])
{
	int A=0, B=0;
	for(int i = 0; i<3;i++)
	{
		scanf("%d",&A);
		scanf("%d",&B);
		printf("Addition is : %d", A+B);
	}
	printf("count argc:%d",argc);
	return 0;
}
