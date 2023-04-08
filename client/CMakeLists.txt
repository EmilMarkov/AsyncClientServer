cmake_minimum_required(VERSION 3.24)

set(DEV_DIR D:/dev/)
set(CMAKE_TOOLCHAIN_FILE ${DEV_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)

project(AsyncClientServer)

include_directories(${DEV_DIR}/vcpkg/installed/x64-windows/include)
link_directories(${DEV_DIR}/vcpkg/installed/x64-windows/lib)
#find_package(boost CONFIG REQUIRED)

add_executable(AsyncClient main.cpp client.cpp)

if(MINGW)
    target_include_directories(AsyncClient PRIVATE ${boost_INCLUDE_DIRS})
    target_link_libraries(AsyncClient PRIVATE ws2_32 ${boost_LIBRARIES})
endif()