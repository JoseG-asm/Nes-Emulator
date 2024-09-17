cmake_minimum_required(VERSION 3.10.2)

project(NES LANGUAGES CXX)

add_library(nes SHARED 
    cpu.cpp
    cpu.h
    bus.cpp
    bus.h
    log.cpp
    log.h
    native-lib.cpp
    types.h
)

target_link_libraries(nes
    PRIVATE
    log
    android
    vulkan
)
