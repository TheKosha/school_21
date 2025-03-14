#ifndef PRINT_MODULE_H
#define PRINT_MODULE_H

#define Module_load_success_message "Output stream module load: success\n"
#define Log_prefix "[LOG]"

/*
    input:  printchar-callback, log message 
    output: void
    result: "Log_prefix HH:MM:SS message"
*/
void print_log(int(*print_funct)(char), const char *sob);

int print_char(char ch);

#endif // PRINT_MODULE_H
