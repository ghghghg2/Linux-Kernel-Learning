#include "stdlib.h"
#include "stdio.h"
#include "dlfcn.h"


int x[2] = {1, 2};
int y[2] = {3, 4};
int z[2];


int main(void)
{

    void *handle;
    void (*addvec)(int *, int *, int *, int);
    char* err_msg;

    // open the shared object file
    handle = dlopen("./libvector.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    addvec = dlsym(handle, "addvec");

    if ((err_msg = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    addvec(x, y, z, sizeof(x));
    printf("z = [%d %d]\n", z[0], z[1]);

    if (dlclose(handle) < 0) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    return 0;

}