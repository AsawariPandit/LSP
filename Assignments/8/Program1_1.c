#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("child process is running with PID : %d\n",getpid());
    return 0;
}