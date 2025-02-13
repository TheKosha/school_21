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

void write_record(FILE *file, int index, DoorState record) {
    fseek(file, index * sizeof(DoorState), SEEK_SET);
    fwrite(&record, sizeof(DoorState), 1, file);
}

int compare_records(const void *a, const void *b) {
    DoorState *recordA = (DoorState *)a;
    DoorState *recordB = (DoorState *)b;

    if (recordA->year != recordB->year) return recordA->year - recordB->year;
    if (recordA->month != recordB->month) return recordA->month - recordB->month;
    if (recordA->day != recordB->day) return recordA->day - recordB->day;
    if (recordA->hour != recordB->hour) return recordA->hour - recordB->hour;
    if (recordA->minute != recordB->minute) return recordA->minute - recordB->minute;
    return recordA->second - recordB->second;
}

void sort_file(FILE *file, int record_count) {
    for (int i = 1; i < record_count; i++) {
        DoorState key = read_record(file, i);
        int j = i - 1;

        while (j >= 0) {
            DoorState temp = read_record(file, j);
            if (compare_records(&temp, &key) > 0) {
                write_record(file, j + 1, temp);
                j--;
            } else {
                break;
            }
        }

        write_record(file, j + 1, key);
    }
}

void print_record(DoorState record) {
    printf("%04d-%02d-%02d %02d:%02d:%02d %d %d\n", record.year, record.month, record.day, record.hour,
           record.minute, record.second, record.status, record.code);
}

void print_file(FILE *file, int record_count) {
    for (int i = 0; i < record_count; i++) {
        DoorState record = read_record(file, i);
        print_record(record);
    }
}

void add_record(FILE *file, int *record_count) {
    DoorState new_record;
    printf("Введите год, месяц, день, час, минуту, секунду, статус, код: ");
    scanf("%d %d %d %d %d %d %d %d", &new_record.year, &new_record.month, &new_record.day, &new_record.hour,
          &new_record.minute, &new_record.second, &new_record.status, &new_record.code);

    write_record(file, *record_count, new_record);
    (*record_count)++;
}

int main(int argc, char *argv[]) {
    int flag = 0;

    if (argc != 2) {
        flag = 1;
    }

    FILE *file = fopen(argv[1], "rb+");
    if (!file) {
        flag = 1;
    }

    if (!flag) {
        fseek(file, 0, SEEK_END);
        int file_size = ftell(file);
        fseek(file, 0, SEEK_SET);

        int record_count = file_size / sizeof(DoorState);
        if (record_count == 0) {
            flag = 1;
        }

        if (!flag) {
            int choice;
            do {
                printf("0 - Вывод содержимого файла\n");
                printf("1 - Сортировка содержимого файла и вывод на экран\n");
                printf("2 - Добавление записи, сортировка и вывод на экран\n");
                printf("Выберите пункт: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 0:
                        print_file(file, record_count);
                        break;
                    case 1:
                        sort_file(file, record_count);
                        print_file(file, record_count);
                        break;
                    case 2:
                        add_record(file, &record_count);
                        sort_file(file, record_count);
                        print_file(file, record_count);
                        break;
                    default:
                        flag = 1;
                        break;
                }
            } while (choice >= 0 && choice <= 2 && !flag);
        }

        fclose(file);
    }

    if (flag) {
        printf("n/a\n");
    }

    return 0;
}