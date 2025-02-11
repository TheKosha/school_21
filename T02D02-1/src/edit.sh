#!/bin/bash
read -p 'Введите путь к файлу: ' File
read -p 'Введите строку, которую нужно изменить: ' Str
read -p 'Введите новую строку: ' New_str
if [ ! -f "File" ]; then
    echo "Файл не существует"
fi
sed -i '' "s/$Str/$New_str/" "$File"
Info=$(realpath "$File")
RelativePath=$(echo "$Info" | awk -F'/src/' '{print "src/"$2}')
Size=$(stat -f "%z" "$File")
Date=$(stat -f "%SB" "$File")
SHA256=$(shasum -a 256 "$File" | awk '{print $1}')
echo "$RelativePath - $Size - $Date - $SHA256 - sha256" >> files.log

