#include "sys/types.h"
#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "errno.h"
#include "wait.h"

#define N 10


pid_t Fork(void); // fork() error handling wrapper
void unix_error(char *msg); // print error on the terminal

int main()
{
    pid_t pid;
    int status, i;

    // Create N children which exit immediately
    for (i = 0; i < N; i++) {
        if (Fork() == 0) {
            exit(100 + i);
        }
    }

    // wait for child terminated
    while ((pid = waitpid(-1, &status, 0)) > 0) {
        if (WIFEXITED(status)) {
            printf("Child %d exit normally with exit status = %d \n", pid, WEXITSTATUS(status));
        } else {
            printf("Child %d exit abnormally. \n", pid);
        }
    }

    if (errno != ECHILD) {
        unix_error("waitpid error\n");
    }

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