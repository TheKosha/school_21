#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"

#define MAX_FILE_NAME_LENGTH 256
#define MAX_TEXT_LENGTH 256
#define MAX_OUTPUT_LENGTH 10000

void add_res(char *result, const char *line) {
    strcat(result, line);
    strcat(result, "\n");
}

void read_file(const char *File_name, char *result, FILE *log_file) {
    if (log_file) {
        logcat(log_file, File_name, INFO);
    }
    FILE *file = fopen(File_name, "r");
    if (file == NULL) {
        add_res(result, "n/a");
        if (log_file) {
            logcat(log_file, "Failed to open file for reading.", ERROR);
        }
    } else {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            line[strcspn(line, "\n")] = 0;
            add_res(result, line);
        }
        fclose(file);
        if (log_file) {
            logcat(log_file, "File read successfully.", INFO);
        }
    }
}

void w_file(const char *File_name, const char *text, char *result, FILE *log_file) {
    if (log_file) {
        logcat(log_file, File_name, INFO);
    }
    FILE *file_check = fopen(File_name, "r");
    if (file_check == NULL) {
        add_res(result, "n/a");
        if (log_file) {
            logcat(log_file, "File does not exist.", WARNING);
        }
        return;
    }
    fclose(file_check);

    FILE *file = fopen(File_name, "a");
    if (file == NULL) {
        add_res(result, "n/a");
        if (log_file) {
            logcat(log_file, "Failed to open file for appending.", ERROR);
        }
        return;
    }

    fprintf(file, "%s\n", text);
    fclose(file);

    FILE *file_read = fopen(File_name, "r");
    if (file_read == NULL) {
        add_res(result, "n/a");
        if (log_file) {
            logcat(log_file, "Failed to read file after appending.", ERROR);
        }
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file_read)) {
        line[strcspn(line, "\n")] = 0;
        add_res(result, line);
    }
    fclose(file_read);

    if (log_file) {
        logcat(log_file, "Text appended to file.", INFO);
    }
}

void xor_encrypt_file(const char *filename, unsigned char key, char *result, FILE *log_file) {
    if (log_file) {
        logcat(log_file, filename, INFO);
    }
    FILE *file = fopen(filename, "rb+");
    if (file == NULL) {
        add_res(result, "Error: Unable to open file for XOR encryption.");
        if (log_file) {
            logcat(log_file, "Failed to open file for XOR encryption.", ERROR);
        }
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *data = malloc(file_size);
    if (data == NULL) {
        fclose(file);
        add_res(result, "Error: Memory allocation failed.");
        if (log_file) {
            logcat(log_file, "Memory allocation failed.", ERROR);
        }
        return;
    }

    fread(data, 1, file_size, file);
    for (long i = 0; i < file_size; i++) {
        data[i] ^= key;
    }

    rewind(file);
    fwrite(data, 1, file_size, file);
    fclose(file);
    free(data);

    add_res(result, "XOR encryption applied.");
    if (log_file) {
        logcat(log_file, "XOR encryption applied.", INFO);
    }
}

void clear_file(const char *filename, FILE *log_file) {
    if (log_file) {
        logcat(log_file, filename, INFO);
    }
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fclose(file);
        if (log_file) {
            logcat(log_file, "File cleared.", INFO);
        }
    } else {
        if (log_file) {
            logcat(log_file, "Failed to clear file.", ERROR);
        }
    }
}

void caesar_cipher_file(const char *filename, int shift, char *result, FILE *log_file) {
    if (log_file) {
        logcat(log_file, filename, INFO);
    }
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        add_res(result, "Error: Unable to open file for Caesar cipher.");
        if (log_file) {
            logcat(log_file, "Failed to open file for Caesar cipher.", ERROR);
        }
        return;
    }

    char *content = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&content, &len, file)) != -1) {
        for (int i = 0; i < read; i++) {
            if (content[i] >= 'a' && content[i] <= 'z') {
                content[i] = 'a' + (content[i] - 'a' + shift) % 26;
            } else if (content[i] >= 'A' && content[i] <= 'Z') {
                content[i] = 'A' + (content[i] - 'A' + shift) % 26;
            }
        }
        fseek(file, -read, SEEK_CUR);
        fputs(content, file);
    }

    free(content);
    fclose(file);

    add_res(result, "Caesar cipher applied.");
    if (log_file) {
        logcat(log_file, "Caesar cipher applied.", INFO);
    }
}

void process_directory_xor(const char *dir_path, unsigned char key, char *result, FILE *log_file) {
    if (log_file) {
        logcat(log_file, dir_path, INFO);
    }
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        add_res(result, "Error: Unable to open directory for XOR processing.");
        if (log_file) {
            logcat(log_file, "Failed to open directory for XOR processing.", ERROR);
        }
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        size_t name_len = strlen(ent->d_name);
        char filepath[2048];
        snprintf(filepath, sizeof(filepath), "%s/%s", dir_path, ent->d_name);

        if (name_len >= 2 && strcmp(ent->d_name + name_len - 2, ".c") == 0) {
            xor_encrypt_file(filepath, key, result, log_file);
        } else if (name_len >= 2 && strcmp(ent->d_name + name_len - 2, ".h") == 0) {
            clear_file(filepath, log_file);
        }
    }

    closedir(dir);
    add_res(result, "Directory processed (XOR).");
    if (log_file) {
        logcat(log_file, "Directory processed with XOR encryption.", INFO);
    }
}

void process_directory_caesar(const char *dir_path, int shift, char *result, FILE *log_file) {
    if (log_file) {
        logcat(log_file, dir_path, INFO);
    }
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        add_res(result, "Error: Unable to open directory for Caesar processing.");
        if (log_file) {
            logcat(log_file, "Failed to open directory for Caesar processing.", ERROR);
        }
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        size_t name_len = strlen(ent->d_name);
        char filepath[2048];
        snprintf(filepath, sizeof(filepath), "%s/%s", dir_path, ent->d_name);

        if (name_len >= 2 && strcmp(ent->d_name + name_len - 2, ".c") == 0) {
            caesar_cipher_file(filepath, shift, result, log_file);
        } else if (name_len >= 2 && strcmp(ent->d_name + name_len - 2, ".h") == 0) {
            clear_file(filepath, log_file);
        }
    }

    closedir(dir);
    add_res(result, "Directory processed (Caesar).");
    if (log_file) {
        logcat(log_file, "Directory processed with Caesar cipher.", INFO);
    }
}

int main() {
    char log_filename[] = "logger.log";
    FILE *log_file = NULL;

    initialize_logger(log_filename, &log_file);

    char File_name[MAX_FILE_NAME_LENGTH] = {0};
    int n = 0;
    char result[MAX_OUTPUT_LENGTH] = {0};

    while (1) {
        if (scanf("%d", &n) != 1) {
            add_res(result, "n/a");
            while (getchar() != '\n');
            continue;
        }
        if (n == -1) {
            break;
        }
        if (n == 1) {
            scanf("%255s", File_name);
            read_file(File_name, result, log_file);
        } else if (n == 2) {
            char text[MAX_TEXT_LENGTH];
            scanf(" %255[^\n]", text);
            w_file(File_name, text, result, log_file);
        } else if (n == 3) {
            char dir_path[MAX_FILE_NAME_LENGTH];
            int shift;
            scanf("%255s %d", dir_path, &shift);
            process_directory_caesar(dir_path, shift, result, log_file);
        } else if (n == 4) {
            char dir_path[MAX_FILE_NAME_LENGTH];
            unsigned char key = 0x5A;
            scanf("%255s", dir_path);
            process_directory_xor(dir_path, key, result, log_file);
        } else {
            add_res(result, "n/a");
        }
    }

    finalize_logger(log_file);

    printf("%s", result);
    return 0;
}