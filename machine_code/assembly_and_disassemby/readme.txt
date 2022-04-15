## build mstore.c

## compile and asssembly
gcc -Og -S mstore.c

# -Og means apply a level of optimization that yields machine code that 
# follows the overall structure of the original C code

## build object
gcc -Og -c mstore.c


## disassemly
objdump -d mstore.o > disassembly.txt
