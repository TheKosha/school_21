all: state_sort state_search

state_sort: state_sort.c
	mkdir -p build
	gcc -Wall -Wextra -Werror -std=c99 -c state_sort.c -o state_sort.o
	gcc -Wall -Wextra -Werror -std=c99 state_sort.o -o ../build/Quest_1
	rm -f state_sort.o
state_search: state_search.c
	mkdir -p build
	gcc -Wall -Wextra -Werror -std=c99 -c state_search.c -o state_search.o
	gcc -Wall -Wextra -Werror -std=c99 state_search.o -o ../build/Quest_2
	rm -f state_search.o
clean:
	rm ../build/Quest_1 ../build/Quest_2
reubild:
	clean all