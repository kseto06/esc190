cmake_minimum_required(VERSION 3.29)
project(esc190)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g -O0")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    message(STATUS "Enabling AddressSanitizer for Debug build")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fsanitize=address")
    set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} -fsanitize=address")
endif()

add_executable(esc190
        review/midterm/2023midterm/Contents/Resources/DWARF/midter2023
        review/midterm/2023midterm/Contents/Resources/Relocations/aarch64/midter2023.yml
        review/midterm/2023midterm/Contents/Info.plist
        review/midterm/2023midterm/midterm2023.dSYM/Contents/Resources/DWARF/midterm2023
        review/midterm/2023midterm/midterm2023.dSYM/Contents/Resources/Relocations/aarch64/midterm2023.yml
        review/midterm/2023midterm/midterm2023.dSYM/Contents/Info.plist
        review/midterm/2023midterm/businesses.txt
        review/midterm/2023midterm/midter2023
        review/midterm/2023midterm/midterm2023
        review/midterm/2023midterm/midterm2023.c)
