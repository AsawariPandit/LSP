#include<stdio.h>
#include<unistd.h>
int main()
{
    int cpid = 0, ExitStatus = 0;
    int Ret = 0;
    Ret = fork();
    if(Ret == 0)
    {
        execl("./ChildProcess2_2",NULL,NULL);
    }
    else
    {
        cpid = wait(&ExitStatus);
        printf("Child process ends with PID : %d and exit status : %d\n",cpid,ExitStatus);
        printf("Parent process completed with PID : %d\n",getpid());
    }
    return 0;
}

// gcc Program2_3.c -o ChildProcess2_3
// gcc Program2_2.c -o ChildProcess2_2
// gcc Program2_1.c -o MyExe
// MyExe