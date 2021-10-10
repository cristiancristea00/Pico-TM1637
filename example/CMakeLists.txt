cmake_minimum_required(VERSION 3.13)

# Set C and C++ and versions
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

# Set default build type to Release
if (NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
    message("Using by default the Release build")
endif ()

# Include the Raspberry Pi Pico SDK import script
include(pico_sdk_import.cmake)

# Project
project(Pico_TM1637 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable
add_executable(Pico_TM1637 main.cpp ../TM1637.cpp)
# Generate header file based on PIO assembly
pico_generate_pio_header(Pico_TM1637 ${CMAKE_CURRENT_LIST_DIR}/../TM1637.pio)

# Add program info
pico_set_program_name(Pico_TM1637 "TODO")
pico_set_program_version(Pico_TM1637 "1.0.0")
pico_set_program_url(Pico_TM1637 "https://github.com/cristiancristea00/Pico-TM1637")
pico_set_program_description(Pico_TM1637 "Copyright (c) 2021 Cristian Cristea")

# Disable serial
pico_enable_stdio_uart(Pico_TM1637 0)
pico_enable_stdio_usb(Pico_TM1637 0)

# Add the libraries to the build
target_link_libraries(Pico_TM1637 pico_stdlib hardware_pio)

# Add pico extras
pico_add_extra_outputs(Pico_TM1637)

# Set float and double implementation
pico_set_float_implementation(Pico_TM1637 pico)
pico_set_double_implementation(Pico_TM1637 pico)

# Set Debug build compiler arguments
set(CMAKE_CXX_FLAGS_DEBUG "-pipe -g -O0 -Wfatal-errors -Wpedantic -Wall -Wextra -Wconversion -Wshadow=local -Wdouble-promotion -Wformat=2 -Wformat-overflow=2 -Wformat-nonliteral -Wformat-security -Wformat-truncation=2 -Wnull-dereference -Wimplicit-fallthrough=3 -Wshift-overflow=2 -Wswitch-default -Wunused-parameter -Wunused-const-variable=2 -Wstrict-overflow=4 -Wstringop-overflow=3 -Wsuggest-attribute=pure -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wmissing-noreturn -Wsuggest-attribute=malloc -Wsuggest-attribute=format -Wmissing-format-attribute -Wsuggest-attribute=cold -Walloc-zero -Walloca -Wattribute-alias=2 -Wduplicated-branches -Wcast-qual")
set(CMAKE_C_FLAGS_DEBUG "-pipe -g -O0 -Wfatal-errors -Wpedantic -Wall -Wextra -Wconversion -Wshadow=local -Wdouble-promotion -Wformat=2 -Wformat-overflow=2 -Wformat-nonliteral -Wformat-security -Wformat-truncation=2 -Wnull-dereference -Wimplicit-fallthrough=3 -Wshift-overflow=2 -Wswitch-default -Wunused-parameter -Wunused-const-variable=2 -Wstrict-overflow=4 -Wstringop-overflow=3 -Wsuggest-attribute=pure -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wmissing-noreturn -Wsuggest-attribute=malloc -Wsuggest-attribute=format -Wmissing-format-attribute -Wsuggest-attribute=cold -Walloc-zero -Walloca -Wattribute-alias=2 -Wduplicated-branches -Wcast-qual")

# Set Release build compiler arguments
set(CMAKE_CXX_FLAGS_RELEASE "-pipe -O2 -fno-builtin")
set(CMAKE_C_FLAGS_RELEASE "-pipe -O2 -fno-builtin")
