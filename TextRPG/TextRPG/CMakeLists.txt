cmake_minimum_required(VERSION 3.20)

project(TextRPG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 1.11.0
)

FetchContent_MakeAvailable(cpr)

add_executable(TextRPG
    main.cpp
    OllamaClient.cpp
)

target_link_libraries(TextRPG
    PRIVATE
    cpr::cpr
)