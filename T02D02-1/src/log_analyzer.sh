#!/bin/bash
read -p "Введите путь до файла: " file
if [ ! -f "$file" ]; then
    echo "Ошибка: файл '$file' не найден."
    exit 1
fi
total_records=$(wc -l < "$file")
unique_files=$(awk '{print $1}' "$file" | sort | uniq | wc -l)
changes_count=$(awk -F ' - ' '{if ($4 != "NULL") print $4}' "$file" | uniq | wc -l)
printf "%d %d %d\n" "$total_records" "$unique_files" "$changes_count"
