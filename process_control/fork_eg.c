#include "sys/types.h"
#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "errno.h"


pid_t Fork(void); // fork() error handling wrapper
void unix_error(char *msg); // print error on the terminal

int main()
{
    pid_t pid;
    int x = 1;

    pid = Fork();

    if (pid == 0) { // Child process
        printf("child: x = %d \n", ++x);
        printf("parent's pid = %d \n", getppid());
        exit(0);
    }

    // Parent
    printf("parent: x = %d \n", --x);
    printf("child's pid = %d \n", pid);
    exit(0);
}



pid_t Fork(void)
{
    pid_t pid;
    pid = fork();

    if (pid < 0) { // error happened
        unix_error("fork error");
    }
}

void unix_error(char *msg)
{
    fprintf(stderr, "%s: %s \n", msg, strerror(errno));
    exit(0);
}