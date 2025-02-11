#!/bin/bash

# Определение цветов
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # Без цвета

if [ "$#" -ne 1 ]; then
    echo -e "${RED}Использование: $0 <имя_файла.c>${NC}"
    exit 1
fi

file=$1

if [ ! -f "$file" ]; then
    echo -e "${RED}Файл $file не найден.${NC}"
    exit 1
fi

# Создание файла .clang-format, если он не существует
if [ ! -f .clang-format ]; then
    echo -e "${YELLOW}Создание файла .clang-format с настройками...${NC}"
    cat <<EOL > .clang-format
---
BasedOnStyle: Google
IndentWidth: 4
ColumnLimit: 110
EOL
    echo -e "${GREEN}Файл .clang-format создан.${NC}"
else
    echo -e "${GREEN}Файл .clang-format уже существует.${NC}"
fi

# Запуск cppcheck
echo -e "${YELLOW}Запуск cppcheck...${NC}"
cppcheck --enable=all --suppress=missingIncludeSystem "$file"
if [ $? -ne 0 ]; then
    echo -e "${RED}Ошибки cppcheck.${NC}"
fi

# Запуск clang-format
echo -e "${YELLOW}Запуск clang-format для форматирования кода...${NC}"
clang-format -i "$file"
echo -e "${GREEN}Файл $file отформатирован.${NC}"

# Компиляция кода
echo -e "${YELLOW}Компиляция кода...${NC}"
executable="${file%.c}"
gcc -Wall -Wextra -Werror -o "$executable" "$file"
if [ $? -ne 0 ]; then
    echo -e "${RED}Ошибки компиляции.${NC}"
    exit 1
fi

echo -e "${GREEN}Файл $file успешно скомпилирован в $executable ${NC}"