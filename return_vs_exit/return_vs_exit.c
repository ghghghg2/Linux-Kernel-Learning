#include "stdio.h"
#include "stdlib.h"

static char *leave_msg;

void cleanup(void)
{
    printf("Message = \" %s \"\n", leave_msg);
}

int main() 
{
    // This will copy the content in the string pool to local array.
    char local_msg[] = "This is a local message in main(), should be out of lifetime after main().";
    // leave_msg point to local_msg[]
    leave_msg = local_msg;
    // register the exit function
    atexit(cleanup);

#ifdef USE_EXIT
    printf("Exit by exit(0):\n");
    exit(0); // call the function registered by atexit() in the reversed order.
#else
    printf("Exit by return 0:\n");
    return 0;
#endif

}