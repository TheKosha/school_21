#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
} DoorState;

DoorState read_record(FILE *file, int index) {
    DoorState record;
    fseek(file, index * sizeof(DoorState), SEEK_SET);
    fread(&record, sizeof(DoorState), 1, file);
    return record;
}

int is_date_match(DoorState record, int search_day, int search_month, int search_year) {
    return (record.day == search_day && record.month == search_month && record.year == search_year);
}

int get_file_size(FILE *file) {
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}

int parse_date(char *date_str, int *day, int *month, int *year) {
    return sscanf(date_str, "%d.%d.%d", day, month, year) == 3;
}

int main(int argc, char *argv[]) {
    int flag = 0;

    if (argc != 3) {
        flag = 1;
    }

    FILE *file = NULL;
    if (!flag) {
        file = fopen(argv[1], "rb");
        if (!file) {
            flag = 1;
        }
    }

    int file_size = 0;
    if (!flag) {
        file_size = get_file_size(file);
        if (file_size == 0) {
            flag = 1;
        }
    }

    int search_day, search_month, search_year;
    if (!flag && !parse_date(argv[2], &search_day, &search_month, &search_year)) {
        flag = 1;
    }

    if (!flag) {
        int record_count = file_size / sizeof(DoorState);
        for (int i = 0; i < record_count; i++) {
            DoorState record = read_record(file, i);
            if (is_date_match(record, search_day, search_month, search_year)) {
                printf("%d\n", record.code);
                fclose(file);
                return 0;
            }
        }
        flag = 1;
    }

    if (file) {
        fclose(file);
    }

    if (flag) {
        printf("n/a\n");
    }

    return 0;
}