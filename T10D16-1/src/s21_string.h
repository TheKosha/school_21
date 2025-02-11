#ifndef S21_STRING_H
#define S21_STRING_H
#include <stdio.h>
size_t s21_strlen(const char *str);
int s21_strcmp(const char *s1, const char *s2);
char *s21_strcpy(char *dest, const char *src);
char *s21_strcat(char *dest, const char *src);
#endif