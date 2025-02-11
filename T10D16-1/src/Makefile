TEST_TARGET ?= strlen_tests s21_strlen strcpy_tests s21_strcat
all: strlen_tests s21_strlen strcpy_tests s21_strcat
strlen_tests:
	gcc -DTEST_STRLEN -c s21_string_test.c -o s21_string_test.o
	gcc -c s21_string.c -o s21_string.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest_1

s21_strlen:
	gcc -DTEST_STRCMP -c s21_string_test.c -o s21_string_test.o
	gcc -c s21_string.c -o s21_string.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest_2

strcpy_tests:
	gcc -DTEST_STRCPY -c s21_string_test.c -o s21_string_test.o
	gcc -c s21_string.c -o s21_string.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest_3

s21_strcat:
	gcc -DSTRCAT_TEST -c s21_string_test.c -o s21_string_test.o
	gcc -c s21_string.c -o s21_string.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest_4

clean:
	rm s21_string_test.o s21_string.o ../build/Quest_1 ../build/Quest_2 ../build/Quest_3 ../build/Quest_4