cmake_minimum_required(VERSION 3.14)
project(estrutura_dados C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(estrutura_dados
        src/lista-linear-sequencial-tests.c
        src/lista-linear-sequencial.c
        src/lista-linear-sequencial.h
        )
