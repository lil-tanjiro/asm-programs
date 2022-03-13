cp_compile:
	@echo "Compile..."
	@nasm -f elf ./src/cp.asm -o cp.o
	@ld -m elf_i386 cp.o -o cp
	@rm cp.o
	@echo "Success!"