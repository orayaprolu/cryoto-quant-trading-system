#pragma once

#include <cstdint>
#include <fstream>
#include <string>
#include "Candle.hpp"

class CandleStream {
public:
    CandleStream(const std::string& filepath);
    void advance();
    void advance(const int64_t timestamp);
    bool isDone() const { return done; };
    const Candle& current() const { return currentCandle; };

private:
    std::ifstream file;
    Candle currentCandle;
    bool done = false;
};
