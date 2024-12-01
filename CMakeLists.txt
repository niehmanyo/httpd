cmake_minimum_required(VERSION 3.27)
project(project1 C)

set(CMAKE_C_STANDARD 11)

add_executable(project1
        main.c
        httpd.cpp

)

target_link_libraries(httpd Ws2_32)
