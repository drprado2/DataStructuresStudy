cmake_minimum_required(VERSION 3.14)
project(estrutura_dados C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(estrutura_dados
        src/SequentialLinkedList/SequentialLinkedListTests.c
        src/SequentialLinkedList/SequentialLinkedList.c
        src/SequentialLinkedList/SequentialLinkedList.h
        src/Application.c src/Helpers/Helpers.c src/Helpers/Helpers.h src/SequentialLinkedList/SequentialLinkedListTests.h)
