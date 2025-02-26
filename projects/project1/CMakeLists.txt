cmake_minimum_required(VERSION 3.10)
project(Project1 C)
set(SOURCES main.c autocomplete.c case_maker.c case_tester.c) # Added case_maker.c
add_executable(Project1 ${SOURCES})
include_directories(${CMAKE_SOURCE_DIR})