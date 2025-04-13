#ifndef CANDLE_HPP
#define CANDLE_HPP

#include <string>
#include <sstream>
#include <cstdint>

struct Candle {
    int64_t timestamp;
    double open;
    double high;
    double low;
    double close;
    double volume;

    std::string toString() const {
        std::ostringstream oss;
        oss << timestamp << " | "
            << open << " "
            << high << " "
            << low << " "
            << close << " "
            << volume;
        return oss.str();
    }
};

#endif
