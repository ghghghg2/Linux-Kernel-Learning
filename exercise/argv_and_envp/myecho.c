/*
 Write a program called myecho that prints its command line arguments and environment variable
*/

#include "stdlib.h"
#include "stdio.h"
#include "string.h"



int main (int argc, char **argv, char **envp)
{
    int i = 0; 

    printf("Command Line arguments: \n");
    while (argv[i] != NULL) {
        printf("argv[%d] = %s \n", i, argv[i]);
        i++;
    }

    i = 0;

    printf("Environment Variables: \n");
    while (envp[i] != NULL) {
        printf("envp[%d] = %s \n", i, argv[i]);
        i++;
    }
    
    exit(EXIT_SUCCESS);
}