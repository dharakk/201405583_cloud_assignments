
Translating 32 bit assembly code to 64 bit assembly code:

32 bit assembly code: asm32.asm

nasm -f elf64 -l asm32.lst  asm32.asm
gcc -m64 -o asm32  asm32.o
./asm32


64 bit assembly code: asm64.asm

nasm -f elf64 -l asm64.lst  asm64.asm
gcc -m64 -o asm64  asm64.o
./asm64