cmake_minimum_required(VERSION 3.16)
project(kv_store LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.0
)
FetchContent_MakeAvailable(Catch2)

set(HASHTABLE_SOURCES kv-store/src/main/hashtable.cpp)

add_executable(kv_store kv-store/src/main/main.cpp ${HASHTABLE_SOURCES})
target_include_directories(kv_store PRIVATE kv-store/src/include)

add_executable(kv_store_tests kv-store/src/test/test_hashtable.cpp ${HASHTABLE_SOURCES})
target_include_directories(kv_store_tests PRIVATE kv-store/src/include)
target_link_libraries(kv_store_tests PRIVATE Catch2::Catch2WithMain)