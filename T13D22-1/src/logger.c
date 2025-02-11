#include "logger.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

const char* log_level_to_string(log_level level) {
    switch (level) {
        case DEBUG:
            return "DEBUG";
        case TRACE:
            return "TRACE";
        case INFO:
            return "INFO";
        case WARNING:
            return "WARNING";
        case ERROR:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}

FILE* log_init(const char* filename) { return fopen(filename, "a"); }

int logcat(FILE* log_file, const char* message, log_level level) {
    if (!log_file || !message) return -1;

    time_t now = time(NULL);
    struct tm* local_time = localtime(&now);

    char timestamp[32];
    strftime(timestamp, sizeof(timestamp), "%T", local_time);

    fprintf(log_file, "[%s] [%s] %s\n", timestamp, log_level_to_string(level), message);
    fflush(log_file);
    return 0;
}

int log_close(FILE* log_file) {
    if (log_file) {
        fclose(log_file);
        return 0;
    }
    return -1;
}

void initialize_logger(const char* log_filename, FILE** log_file) {
    *log_file = log_init(log_filename);
    if (!*log_file) {
        printf("Failed to initialize logger.\n");
    } else {
        logcat(*log_file, "Logger initialized.", INFO);
    }
}

void finalize_logger(FILE* log_file) {
    if (log_file) {
        logcat(log_file, "Logger closed.", INFO);
        log_close(log_file);
    }
}