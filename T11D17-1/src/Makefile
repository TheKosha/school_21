СС = gcc -Wall -Wextra -Werror
Target:door_struct list_test
all:door_struct list_test 
door_struct: dmanager_module.o 
	$(CC) -c dmanager_module.c -o dmanager_module.o 
	$(CC) dmanager_module.o -o ../build/Quest_1
list_test: list_test.o list.o
	$(CC) -c list.c -o list.o
	$(CC) -c list_test.c -o list_test.o
	$(CC) list_test.o list.o -o ../build/Quest_2


clean: 
	rm dmanager_module.o list_test.o list.o ../build/Quest_1 ../build/Quest_2
rebuild:
	make clean 
	make all