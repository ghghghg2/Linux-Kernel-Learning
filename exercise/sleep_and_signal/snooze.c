#include "../../csapp.h"

void usage (void)
{
    printf("Usage: ./snooze [secs]\n");
    exit(0);
}

void sig_handler (int sig)
{
    return;
}

int main (int argc, char **argv, char **envp)
{
    
    int cmd_s = 0;
    int remain_s;
    
    if (argc != 2) { // check arg num
        usage();
    }

    int i = 0;
    while (argv[1][i] >= '0' && argv[1][i] <= '9') { // extract the number
        cmd_s = 10 * cmd_s + (argv[1][i] - '0');
        i++;
    }
 
    Signal(SIGINT, sig_handler); // set dummy handler for SIGINT

    remain_s = Sleep(cmd_s);

    printf("\nSlept for %d of %d secs\n", cmd_s - remain_s, cmd_s);

    exit(0);
}