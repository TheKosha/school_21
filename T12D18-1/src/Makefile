COMP = gcc -Wall -Wextra -Werror
all:print_module
print_module: print_module.o main_module_entry_point.o
	$(COMP) -c print_module.c -o print_module.o
	$(COMP) print_module.o main_module_entry_point.o -o ../build/Quest_1
	rm print_module.o main_module_entry_point.o
clean:
	rm ../build/Quest_1
rebuilt:
	make clean
	make all