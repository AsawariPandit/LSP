#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
struct Student
{
    int rollNo;
    char name[30];
    float marks;
};
int main(int argc, char *argv[])
{
    struct Student sobj, sobj1;
    int fd = 0, Ret = 0;
    char Buffer[20];
    if(argc != 5)
    {
        printf("Insufficient Arguments. \n Please enter Filename, Roll No, Name and Marks of Student\n");
        return -1;
    }

    sobj.rollNo = atoi(argv[2]);
    strcpy(sobj.name, argv[3]);
    sobj.marks = atof(argv[4]);
    fd = open(argv[1], O_WRONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    write(fd, &sobj, sizeof(sobj));
    close(fd);
    fd = open(argv[1], O_RDONLY);
    Ret = read(fd, &sobj1, sizeof(sobj1));
    printf("Roll No : %d , Name : %s, Marks : %f", sobj1.rollNo, sobj1.name, sobj1.marks);
    close(fd);
    return 0;
}