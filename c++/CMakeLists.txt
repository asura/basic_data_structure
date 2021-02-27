cmake_minimum_required(VERSION 3.16)

project(
    sample
    LANGUAGES CXX
    VERSION 0.1.0
)

set(CMAKE_CXX_STANDARD 17)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)

add_executable(
    sample
    main.cpp
    set.cpp
    vector.cpp
)

target_link_libraries(
    sample
    PRIVATE Catch2::Catch2
)
