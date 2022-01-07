#include <signal.h> /* signal() */
#include <stdio.h>  /* printf() */
#include <stdlib.h> /* abort()  */


#include <signal.h> /* signal() */
#include <stdio.h>  /* printf() */
#include <stdlib.h> /* abort()  */


#include "errno.h"
#include "string.h"

void handler_nonportable(int sig)
{
    /* undefined behavior, maybe fine on specific platform */
    printf("Catched: %d\n", sig);

    /* abort is safe to call */
    abort();
}

sig_atomic_t volatile finished = 0;

void handler(int sig)
{
    switch (sig) {
        /* hardware interrupts should not return */
    case SIGSEGV:
        printf ("Segment Error!\n");
        printf ("Error Number: %d\n", errno); // set by specified lib function, e.g. fopen()
        printf ("Message by strerr: %s \n", strerror(errno));
        perror ("Message by perror");
        //_Exit(EXIT_FAILURE);
        break;
    case SIGFPE:
        printf ("Arithmetic Error!\n");
        printf ("Error Number: %d\n", errno);
        printf ("Message by strerr: %s \n", strerror(errno));
        perror ("Message by perror");
        break;
    case SIGILL:
        /* quick_exit is safe to call */
        //_Exit(EXIT_FAILURE);
        break;
    default:
        /* Reset the signal to the default handler,
         * so we will not e called again if things go
         * wrong on return.
         */
        signal(sig, SIG_DFL);
        return;
    }

    /* let everybody know that we are finished */
    finished = sig;
    if (finished) {
        fprintf(stderr, "we have been terminated by signal %d\n",
                (int) finished);
        _Exit(EXIT_FAILURE);
    }
}
int main(void)
{
    /* Catch the SIGSEGV signal, raised on segmentation faults
     * (i.e NULL ptr access)
     */
    if (signal(SIGSEGV, &handler) == SIG_ERR) {
        perror("could not establish handler for SIGSEGV");
        return EXIT_FAILURE;
    }

    /* Catch the SIGFPE signal, termination request */
    if (signal(SIGFPE, &handler) == SIG_ERR) {
        perror("could not establish handler for SIGFPE");
        return EXIT_FAILURE;
    }

    /* Catch the SIGTERM signal, termination request */
    if (signal(SIGTERM, &handler) == SIG_ERR) {
        perror("could not establish handler for SIGTERM");
        return EXIT_FAILURE;
    }

    /* Ignore the SIGINT signal, by setting the handler to `SIG_IGN`. */
    signal(SIGINT, SIG_IGN);

    /* Do something that takes some time here, and leaves
     * the time to terminate the program from the keyboard.
     */


    /* Try to force a arithmetic fault */
    {
        int a, b, c;
        a = 5;
        b = 0;
        c = a / b;
    }


    /* Try to force a segmentation fault, and raise a SIGSEGV */
    {
        char *ptr = 0;
        /* Trigger the SIGSEGV and enter the handler(), came back here after returning from handler(). So it would
           cause infinete loop because repeatly triggering SIGSEGV.
         */
        *ptr = 0; 
    }
    

    /* This should never be executed */
    return EXIT_SUCCESS;
}