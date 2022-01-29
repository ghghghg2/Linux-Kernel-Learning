#include "../csapp.h"

#define MAX_JOBS_N 10

typedef struct {
    int arr[MAX_JOBS_N];
    int index;
}job_list_t;



job_list_t job_list = {0};

char* my_argv[] = {"echo", "This is a message from child.", NULL};

void add_job(pid_t p)
{
    int i = job_list.index;

    if (i >= MAX_JOBS_N) {
        printf("Exceed the limit of jobs.\n");
        exit(0);
    }
     
    job_list.arr[i] = p;
    job_list.index++;
    printf("%d added.\n", p);
}

void delete_job(pid_t p)
{
    for (int i = 0; i < MAX_JOBS_N; i++) {
        if (job_list.arr[i] == p){
            printf("%d deleted.\n", p);
            job_list.arr[i] = 0;
            job_list.index--;
            return;
        }
    }

    unix_error("Deleting job isn't exist in the list.");
}

void handler(int sig_num)
{
    pid_t pid;
    while ((pid = waitpid(-1, NULL, 0)) > 0) {
        delete_job(pid);
    }
    if (errno != ECHILD) {
        unix_error("waitpid error.\n");
    }
}

int main(void)
{
    pid_t pid;
    sigset_t mask;

    Sigemptyset(&mask); // clear the mask
    Sigaddset(&mask, SIGCHLD);
    Sigprocmask(SIG_BLOCK, &mask, NULL);

    Signal(SIGCHLD, handler); // register the handler for SIGCHLD

    if ((pid = Fork()) == 0) {
        // unblock the SIGCHLD
        Sigprocmask(SIG_UNBLOCK, &mask, NULL);
        // child
        Execve("/usr/bin/echo", my_argv, NULL);
    }
    /* Use the sleep() to simulate that child process precede the parent process.*/
    sleep(1);
    // add job in list
    add_job(pid);
    // unblock the SIGCHLD
    Sigprocmask(SIG_UNBLOCK, &mask, NULL);

    //pause();
    exit(0);
}