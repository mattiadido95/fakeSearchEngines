cmake_minimum_required(VERSION 3.23)
project(fakeSearchEngines)

set(CMAKE_CXX_STANDARD 14)

include_directories(backend)
include_directories(backend/utility)

add_executable(fakeSearchEngines
        backend/utility/FileManager.cpp
        backend/utility/FileManager.h
        backend/utility/utility.cpp
        backend/utility/utility.h
        backend/main.cpp
        backend/preprocessing.cpp
        backend/preprocessing.h)
