cmake_minimum_required (VERSION 3.15)
project(DTavernGame2048 VERSION 1.0.0)

file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/)
file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/build/)

if($ENV{APP_ARCHITECTURE} STREQUAL "x64")
  set(APP_PROJECT_NAME "dtavern-game-2048_${PROJECT_VERSION}")
else()
  set(APP_PROJECT_NAME "dtavern-game-2048_$ENV{APP_ARCHITECTURE}_${PROJECT_VERSION}")
endif()

configure_file(
  ${PROJECT_SOURCE_DIR}/include/config.h.in
  ${CMAKE_BINARY_DIR}/config.h
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

include_directories(${PROJECT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  enable_testing()
  add_subdirectory(tests)
endif()
