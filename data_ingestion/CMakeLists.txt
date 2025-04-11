cmake_minimum_required(VERSION 3.10)
project(binance_fetch)

set(CMAKE_CXX_STANDARD 17)

find_package(CURL REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)

add_executable(binance_fetch src/binance_fetch.cpp)

target_link_libraries(binance_fetch
    CURL::libcurl
    nlohmann_json::nlohmann_json
)
