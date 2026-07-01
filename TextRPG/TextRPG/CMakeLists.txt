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

FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)

FetchContent_MakeAvailable(cpr json)

add_executable(TextRPG
    main.cpp
    OllamaClient.cpp
)

target_link_libraries(TextRPG
    PRIVATE
    cpr::cpr
    nlohmann_json::nlohmann_json
)