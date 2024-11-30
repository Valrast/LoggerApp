# Minimalna wersja CMake
cmake_minimum_required(VERSION 3.10)

# Nazwa projektu
project(LoggerApp)

# Wymagany standard języka
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dodanie źródeł
add_executable(LoggerApp
    main.cpp
    Logger.h
    Log.h
    LogFactory.h
)
