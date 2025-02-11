#include "s21_string.h"

#include <stdio.h>

#ifdef TEST_STRLEN
void test_s21_strlen(const char *str, size_t expected) {
    size_t result = s21_strlen(str);
    printf("Вход: \"%s\"\n", str);
    printf("Ожидаемый выход: %zu\n", expected);
    printf("Выход: %zu\n", result);
    if (result == expected) {
        printf("Результат: SUCCESS\n\n");
    } else {
        printf("Результат: FAIL\n\n");
    }
}
#endif

#ifdef TEST_STRCMP
void test_s21_strcmp(const char *str1, const char *str2, int expected) {
    int result = s21_strcmp(str1, str2);
    printf("Вход 1: \"%s\"\n", str1);
    printf("Вход 2: \"%s\"\n", str2);
    printf("Ожидаемый выход: %d\n", expected);
    printf("Выход: %d\n", result);
    if (result == expected) {
        printf("Результат: SUCCESS\n\n");
    } else {
        printf("Результат: FAIL\n\n");
    }
}
#endif

#ifdef TEST_STRCPY
void test_s21_strcpy(const char *src, const char *expected) {
    char dest[100];
    s21_strcpy(dest, src);
    printf("Вход: \"%s\"\n", src);
    printf("Ожидаемый выход: \"%s\"\n", expected);
    printf("Выход: \"%s\"\n", dest);
    if (s21_strcmp(dest, expected) == 0) {
        printf("Результат: SUCCESS\n\n");
    } else {
        printf("Результат: FAIL\n\n");
    }
}
#endif
#ifdef STRCAT_TEST
void test_s21_strcat(const char *str1, const char *str2, const char *expected) {
    char dest[100];
    s21_strcpy(dest, str1);
    s21_strcat(dest, str2);
    printf("Вход 1: \"%s\"\n", str1);
    printf("Вход 2: \"%s\"\n", str2);
    printf("Ожидаемый выход: \"%s\"\n", expected);
    printf("Выход: \"%s\"\n", dest);
    if (s21_strcmp(dest, expected) == 0) {
        printf("Результат: SUCCESS\n\n");
    } else {
        printf("Результат: FAIL\n\n");
    }
}

#endif

int main() {
#ifdef TEST_STRLEN
    printf("Testing s21_strlen:\n");
    test_s21_strlen("hello", 5);
    test_s21_strlen("", 0);
    test_s21_strlen("a", 1);
    test_s21_strlen("HAHAHA HOW ARE YOU?", 19);
    printf("\n");
#endif
#ifdef TEST_STRCMP
    printf("Testing s21_strcmp:\n");
    test_s21_strcmp("Hello", "Hello", 0);
    test_s21_strcmp("Hello", "Hell", 111);
    test_s21_strcmp("Hell", "Hello", -111);
    test_s21_strcmp("", "", 0);
    test_s21_strcmp("A", "a", -32);
    printf("\n");
#endif
#ifdef TEST_STRCPY
    printf("Testing s21_strcpy:\n");
    test_s21_strcpy("hello", "hello");
    test_s21_strcpy("", "");
    test_s21_strcpy("a", "a");
    test_s21_strcpy("12345", "12345");
    printf("\n");
#endif
#ifdef STRCAT_TEST
    printf("Testing s21_strcat:\n");
    test_s21_strcat("hello", "hello", "hellohello");
    test_s21_strcat("", "", "");
    test_s21_strcat("a", "a", "aa");
    test_s21_strcat("HAHAHA HOW ARE YOU?", "HAHAHA HOW ARE YOU?", "HAHAHA HOW ARE YOU?HAHAHA HOW ARE YOU?");
    printf("\n");
#endif
    return 0;
}