#include "stdio.h"
#include "my_vector.h"


int x[2] = {1, 2};
int y[2] = {3, 4};
int z[2];

int main()
{
    addvec(x, y, z, sizeof(x)/sizeof(x[0]));
    printf("z = [%d, %d]\n", z[0], z[1]);
    return 0;
}