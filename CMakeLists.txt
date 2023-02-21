cmake_minimum_required(VERSION 3.4...3.18)
project(immortality)

add_subdirectory(pybind11)
pybind11_add_module(immortality src/main.cpp)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(immortality PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(immortality PUBLIC Threads::Threads)
target_link_libraries(immortality PUBLIC bio)
set(CMAKE_CXX_LINK_EXECUTABLE "<CMAKE_CXX_COMPILER>  <FLAGS> <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> -Wl,--start-group -Wl,--whole-archive <LINK_LIBRARIES> -Wl,--no-whole-archive -Wl,--end-group")
