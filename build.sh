#!/bin/bash

# Получаем путь до папки, в которой находится файл скрипта
SCRIPT_DIR="$(dirname "$0")"

# Создание папки build, если ее нет
mkdir -p build

# Вызов CMake для генерации файлов проекта
cmake -B "$SCRIPT_DIR/build" "$SCRIPT_DIR"

# Сборка проекта
cmake --build "$SCRIPT_DIR/build" && \


mv "$SCRIPT_DIR/build/client/Debug/AsyncClient.exe" "$SCRIPT_DIR" && \
mv "$SCRIPT_DIR/build/server/Debug/AsyncServer.exe" "$SCRIPT_DIR"
