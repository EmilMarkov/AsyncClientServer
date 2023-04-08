# AsyncClientServer
Asynchronous client-server application written in c++ using the boost/asio library.

# Readme.md для асинхронного клиент-серверного приложения

## Установка библиотеки boost/asio

Для работы с асинхронным клиент-серверным приложением необходимо установить библиотеку boost/asio. 

В данном примере мы будем использовать инструмент vcpkg для установки библиотеки boost/asio. Для установки vcpkg необходимо выполнить следующие шаги:

1. Склонируйте репозиторий vcpkg с помощью команды:

```
git clone https://github.com/microsoft/vcpkg
```

2. Перейдите в директорию vcpkg:

```
cd vcpkg
```

3. Запустите скрипт установки библиотеки boost/asio для Windows (x64):

```
./vcpkg.exe install boost-asio:x64-windows
```

4. Для использования библиотеки boost/asio в проекте необходимо добавить в файл CMakeLists.txt следующие строки:

```
cmake_minimum_required(VERSION 3.24)

set(DEV_DIR D:/dev/)
set(CMAKE_TOOLCHAIN_FILE ${DEV_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)

project(AsyncClient)

include_directories(${DEV_DIR}/vcpkg/installed/x64-windows/include)
link_directories(${DEV_DIR}/vcpkg/installed/x64-windows/lib)

add_executable(AsyncClient main.cpp client.cpp)

if(MINGW)
target_include_directories(AsyncClient PRIVATE ${boost_INCLUDE_DIRS})
target_link_libraries(AsyncClient PRIVATE ws2_32 ${boost_LIBRARIES})
endif()
```

В строке `set(DEV_DIR D:/dev/)` необходимо заменить `D:/dev/` на путь к директории, где находится vcpkg.

С помощью команды `include_directories` добавляем путь к директории, где установлена библиотека boost/asio, а с помощью `link_directories` добавляем путь к директории, где находятся файлы библиотеки.

Для сборки проекта необходимо выполнить следующие команды в терминале:

```
mkdir build
cd build
cmake ..
cmake --build .
```

После сборки проекта можно запустить сервер и клиент с помощью команды `./AsyncServer` и `./AsyncClient`.
