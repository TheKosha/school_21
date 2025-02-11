#include "print_module.h"

#include <stdio.h>
#include <time.h>

int print_char(char ch) { return putchar(ch); }

void print_log(int (*print_funct)(char), const char *sob) {
    time_t it_time = time(NULL);
    if (it_time == (time_t)-1) {
        return;
    }

    struct tm *timik = localtime(&it_time);
    if (timik == NULL) {
        return;
    }
    char time_str[9];
    strftime(time_str, sizeof(time_str), "%T", timik);
    const char masiv_dli_bukv[] = "[LOG] ";
    for (size_t i = 0; masiv_dli_bukv[i] != '\0'; ++i) {
        print_funct(masiv_dli_bukv[i]);
    }
    for (size_t i = 0; time_str[i] != '\0'; ++i) {
        print_funct(time_str[i]);
    }
    print_funct(' ');

    while (*sob) {
        print_funct(*sob++);
    }

    print_funct('\n');
}