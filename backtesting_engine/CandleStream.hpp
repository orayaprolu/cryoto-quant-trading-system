#pragma once

#include <fstream>
#include <string>
#include "Candle.hpp"

class CandleStream {
public:
    CandleStream(const std::string& filepath);
    void advance();
    bool isDone() const { return done; };
    const Candle& current() const { return currentCandle; };

private:
    std::ifstream file;
    Candle currentCandle;
    bool done = false;
};


