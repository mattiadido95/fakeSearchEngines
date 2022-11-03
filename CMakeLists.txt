cmake_minimum_required(VERSION 3.22.1)
project(fakeSearchEngines)

set(CMAKE_CXX_STANDARD 14)

include_directories(backend)
include_directories(backend/utility)

#find_package(PkgConfig)
#pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

add_executable(fakeSearchEngines
#        backend/server/rest_server.cpp
        backend/utility/FileManager.cpp
        backend/utility/FileManager.h
        backend/utility/utility.cpp
        backend/utility/utility.h
        backend/main.cpp
        backend/PorterStemming.cpp
        backend/preprocessing.cpp
        backend/preprocessing.h
        )
