cmake_minimum_required(VERSION 3.22)
project(backend)

#get os_information
execute_process (
        COMMAND bash -c "uname -a  | head -n1 | cut -d ' ' -f1"
        OUTPUT_VARIABLE os_type
)

#if Darwin set clang path
if("${os_type}" STREQUAL "Darwin\n")
    message("${os_type}")
    set(CMAKE_C_COMPILER "/usr/local/opt/llvm/bin/clang")
endif()

# disallow in-source builds
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
message(SEND_ERROR "In-source builds are not allowed.")
endif("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")

# enable warnings (always good)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")
include_directories(.)

# include the STXXL library in my-project
add_subdirectory(stxxl)

# apply STXXL CXXFLAGS to our configuration
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${STXXL_CXX_FLAGS}")

# add STXXL includes path
include_directories(${STXXL_INCLUDE_DIRS})

add_executable(backend
        main.cpp
        preprocessing.cpp
        preprocessing.h
        PorterStemming.cpp
        utility/utility.cpp
        utility/utility.h
        index/Index.cpp
        index/Index.h utility/Print.h utility/Print.cpp utility/definition.h utility/definition.h)

target_link_libraries(backend ${STXXL_LIBRARIES})



