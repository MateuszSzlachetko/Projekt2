cmake_minimum_required(VERSION 3.1)
project(Projekt2)

set(EXECUTABLE ${CMAKE_PROJECT_NAME}_run)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true include/*.h source/*.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(${EXECUTABLE} ${SOURCES})
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})