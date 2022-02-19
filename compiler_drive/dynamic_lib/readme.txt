### 1. build a dynamic library and use it

## build addvec.c multvec.c

## build main.c

## build a dynamic library libvector.so
gcc -shared -fpic libvector.so addvec.c multvec.c


## build prog with built shared library
gcc -o prog main.c ./libvector.so

## execute app
./prog





### 2. use the dyamic library in program

## build load_dyn_lib.c

## compile the load_dyn_lib.c
gcc -rdynamic -o prog2 load_dyn_lib.c -ldl
# -ldl is a shorthand of libdl.so
# -rdynamic Pass the flag -export-dynamic to the ELF linker, on targets that support it. 
# This instructs the linker to add all symbols, not only used ones, to the dynamic symbol table. 
# This option is needed for some uses of dlopen or to allow obtaining backtraces from within a program.

## execute the prog2
./prog2

