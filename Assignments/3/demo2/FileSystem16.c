#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;

    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDWR);
    if(fd == -1)
    {
	fd = creat(argv[1], 0777);
        printf("File is successfully created with fd : %d\n",fd);
        return -1;
    }
    else
    {
        printf("File is succesfully opened with fd : %d\n",fd);
    }

    return 0;
}
