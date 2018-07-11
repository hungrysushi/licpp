
cmake_minimum_required(VERSION 3.0)
project(licpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

add_executable(licpp
        src/main.cpp
        src/eval.cpp
        src/node.cpp
        src/parser.cpp
        src/tokenizer.cpp
        )

target_include_directories(licpp PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

target_link_libraries(licpp LINK_PUBLIC
        edit
        )
