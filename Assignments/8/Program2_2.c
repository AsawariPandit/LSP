#include<stdio.h>
#include<unistd.h>
int main()
{
    int cpid = 0, ExitStatus = 0;
    int Ret = 0;
    printf("Child process 2_2 running with PID : %d\n",getpid());
    Ret = fork();
    if(Ret == 0)
    {
        execl("./ChildProcess2_3",NULL,NULL);
    }
    else
    {
        cpid = wait(&ExitStatus);
        printf("Child process ends with PID : %d and exit status : %d\n",cpid,ExitStatus);
        printf("Parent process completed with PID : %d\n",getpid());
    }
    return 0;
}