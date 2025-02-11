data_stat.a: ../data_libs/data_stat.o
	ar rcs $@ $^
all: Quest_3 Quest_5
Quest_3: main_executable_module.o ../yet_another_decision_module/decision.o ../data_libs/data_io.o ../data_libs/data_stat.o ../data_module/data_process.o ../sort_module/sort.o
	gcc main_executable_module.o ../yet_another_decision_module/decision.o ../data_libs/data_io.o ../data_libs/data_stat.o ../data_module/data_process.o ../sort_module/sort.o -o ../../build/Quest_3
Quest_5: main_executable_module.o ../yet_another_decision_module/decision.o ../data_libs/data_io.o ../data_module/data_process.o ../sort_module/sort.o data_stat.a
	gcc main_executable_module.o ../yet_another_decision_module/decision.o ../data_libs/data_io.o ../data_module/data_process.o ../sort_module/sort.o data_stat.a -o ../../build/Quest_5
main_executable_module.o: ../main_executable_module/main_executable_module.c
	gcc -c ../main_executable_module/main_executable_module.c -o main_executable_module.o
data_io.o: ../data_libs/data_io.c
	gcc -c ../data_libs/data_io.c -o ../data_libs/data_io.o
data_stat.o: ../data_libs/data_stat.c
	gcc -c ../data_libs/data_stat.c -o ../data_libs/data_stat.o
../data_module/data_process.o: ../data_module/data_process.c
	gcc -c -fPIC ../data_module/data_process.c -o ../data_module/data_process.o
decision.o: ../yet_another_decision_module/decision.c
	gcc -c ../yet_another_decision_module/decision.c -o ../yet_another_decision_module/decision.o
sort.o: ../sort_module/sort.c
	gcc -c ../sort_module/sort.c -o ../sort_module/sort.o
clean:
	rm -f main_executable_module.o ../yet_another_decision_module/decision.o ../data_libs/data_io.o ../data_libs/data_stat.o ../data_module/data_process.o ../sort_module/sort.o data_stat.a ../../build/Quest_3 ../../build/Quest_5