#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(int argc, char *argv[])
{
    int fd = 0, Ret = 0;
    char Buffer[50]={'\0'};
    if(argc != 2)
    {
        printf("Insufficient Arguments\n");
    }
    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file. \n");
        return -1;
    }
    while((Ret = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        printf("%s",Buffer);
        memset(Buffer, 0, sizeof(Buffer));
    }
    close(fd);
    return 0;
}