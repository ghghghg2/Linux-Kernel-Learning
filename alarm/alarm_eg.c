#include "csapp.h"


void handler(int sig) 
{
    static int beep;

    printf("BEEP!\n");
    if (++beep < 5) {
        Alarm(1);
    } else {
        printf("BOOM!\n");
        exit(0);
    }

}

int main (void)
{
    Signal(SIGALRM, handler); // register the handler() as handler for alarm signal
    Alarm(1);

    while (1) {
        ;   // return here after handler()
    }
}