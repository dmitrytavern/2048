cmake_minimum_required (VERSION 3.15)
project(DTavernGameApplication VERSION 0.0.0)

configure_file(
  ${PROJECT_SOURCE_DIR}/include/config.h.in
  ${CMAKE_BINARY_DIR}/config.h
)

file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/)
file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/build/)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

include_directories(${PROJECT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(tests)
