#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <time.h>

typedef enum log_level { DEBUG, TRACE, INFO, WARNING, ERROR } log_level;

FILE* log_init(const char* filename);

int logcat(FILE* log_file, const char* message, log_level level);

int log_close(FILE* log_file);

void initialize_logger(const char* log_filename, FILE** log_file);

void finalize_logger(FILE* log_file);

#endif