#include "../csapp.h"

void sig_handler(int sig)
{
    pid_t pid;

    while ( (pid = waitpid(-1, NULL, 0)) > 0) // reap the child as many as possible
        printf("Reap the Child %d \n", (int)pid);
    
    if (errno != ECHILD)
        unix_error("waitpid error");

    Sleep(2);
    return;
}

int main(void) 
{
    /* register sig_handler for SIGCHLD */
    signal(SIGCHLD, sig_handler);


    /* Create 3 childs that print hello msg and exit after 1s */
    for (int i = 0; i < 3; i++) {
        int pid;
        if ((pid = Fork()) == 0) {
            printf("Hello from child %d.\n", pid);
            Sleep(1);
            exit(0);
        }
    }

    int n;
    char buf[MAXBUF];
    while ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0) // auto revoverery if slow system call is interrupted
        if (errno != EINTR)
            unix_error("read error");
    
    printf("Parent processing input\n");
    while (1) {
        ;
    }
    
    exit(0);
}