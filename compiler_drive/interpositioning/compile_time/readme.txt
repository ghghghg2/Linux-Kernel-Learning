## create interpos_compile_time.c mymalloc.h mymalloc.c

## compile mymalloc.c
gcc -DCOMPILETIME -c mymalloc.c

## compile interpos_compile_time.c
gcc -I. -o interpos_compile_time interpos_compile_time.c mymalloc.o
# -I. means search files at . at highest priority

# execute interpos_compile_time
./interpos_compile_time
