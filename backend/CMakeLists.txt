cmake_minimum_required(VERSION 3.23)
project(backend)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(backend
        main.cpp
        preprocessing.cpp
        preprocessing.h
        PorterStemming.cpp utility/utility.cpp utility/utility.h)