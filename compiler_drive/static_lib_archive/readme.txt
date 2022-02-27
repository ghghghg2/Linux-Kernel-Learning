
## build addvec.c multvec.c

## build main.c

## build relocatable obj file
gcc -c addvec.c
gcc -c multvec.c


## build a library of libvector.a
ar rcs libvector.a addvec.o multvec.o


## link the main.o and built lib
gcc -static -o main main.o -L. -lvector


-lvector is a shorthand for libvector.a
-L. indicate gcc to find lib in the current directory


## execute app
./main
