cmake_minimum_required(VERSION 3.10)
project(CryptoQuantTradingPlatform)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

find_package(CURL REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)

add_executable(binance_fetch data_ingestion/binance_fetch.cpp)
add_executable(data_loader
    backtesting_engine/data_loader.cpp
    backtesting_engine/CandleStream.cpp
)
add_executable(strategy_loader backtesting_engine/strategy_loader.cpp)

target_link_libraries(binance_fetch
    CURL::libcurl
    nlohmann_json::nlohmann_json
)
