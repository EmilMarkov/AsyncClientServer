cmake_minimum_required(VERSION 3.24)

set(DEV_DIR D:/dev/)
set(CMAKE_TOOLCHAIN_FILE ${DEV_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)

project(AsyncClientServer)

include_directories(${DEV_DIR}/vcpkg/installed/x64-windows/include)
link_directories(${DEV_DIR}/vcpkg/installed/x64-windows/lib)
#find_package(boost CONFIG REQUIRED)

add_executable(AsyncServer main.cpp server.cpp session.cpp)

if(MINGW)
    target_include_directories(AsyncServer PRIVATE ${boost_INCLUDE_DIRS})
    target_link_libraries(AsyncServer PRIVATE ws2_32 ${boost_LIBRARIES})
    target_link_libraries(AsyncServer PRIVATE wsock32 ${boost_LIBRARIES})
endif()