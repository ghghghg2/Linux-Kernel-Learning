#include "stdio.h"
#include "mymalloc.h"


int main()
{
    int *p = malloc(32);
    free(p);
    return 0;
}