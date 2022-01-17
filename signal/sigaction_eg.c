#include "../csapp.h"

void handler(int n_sig)
{

}


int main(void)
{
    
    struct sigaction act, oldact;
    sigset_t sig_set, old_set;

    act.sa_handler = handler;
    act.sa_flags = SA_RESTART;  /* Restart syscall on signal return. */
    sigemptyset(&act.sa_mask); // clear all signal from set (Only signals of the type currently being processed by the handler are blocked)
    // note. sa_mask determines which signal to blocked during signal_handler()

    sigemptyset(&sig_set); // clear all signal
    sigaddset(&sig_set, SIGINT); // add the SIGINT into sig_set


    sigprocmask(SIG_BLOCK, &sig_set, &old_set); // add the SIGINT to blocked

    // now SIGINT is blocked, user can't stop the process via ctrl+c

    printf("Sleep for 5s\n");
    Sleep(5); 
    printf("\n");

    exit(0);

}