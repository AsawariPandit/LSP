#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int Ret = 0,Exit_Status = 0, cpid = 0;
    Ret = fork();

    if(Ret == 0)
    {
        execl("./ChildProcess","NULL",NULL);
        printf("Child process ends with PID : %d and parent PID : %d",getpid(),getppid());

    }
    else
    {
          cpid = wait(&Exit_Status);
          printf("Child process ends with PID %d and exit status : %d\n",cpid,Exit_Status);
          printf("Parent Process ends with PID : %d\n",getpid());
    }
    return 0;
}
