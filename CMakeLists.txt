cmake_minimum_required(VERSION 3.16)
project(kv_store LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE sources kv-store/src/main/*.cpp)

add_executable(kv_store ${sources})
target_include_directories(kv_store PRIVATE kv-store/src/include)