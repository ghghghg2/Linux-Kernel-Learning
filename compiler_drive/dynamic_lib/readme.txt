
## build addvec.c multvec.c

## build main.c

## build a dynamic library libvector.so
gcc -shared -fpic libvector.so addvec.c multvec.c


## build prog with built shared library
gcc -o prog main.c ./libvector.so


## execute app
./prog
