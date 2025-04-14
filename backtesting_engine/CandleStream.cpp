#include "CandleStream.hpp"
#include <cstdint>
#include <sstream>
#include <string>

CandleStream::CandleStream(const std::string& filepath) {
    file.open(filepath);
    std::string header;
    std::getline(file, header);  // skip header
    advance();  // preload first row
}

void CandleStream::advance() {
    std::string line;
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string item;

        Candle c;

        std::getline(ss, item, ','); c.timestamp = std::stoll(item);
        std::getline(ss, item, ','); c.open = std::stod(item);
        std::getline(ss, item, ','); c.high = std::stod(item);
        std::getline(ss, item, ','); c.low = std::stod(item);
        std::getline(ss, item, ','); c.close = std::stod(item);
        std::getline(ss, item, ','); c.volume = std::stod(item);

        currentCandle = c;
    } else {
        done = true;
    }
}

// Advances to timestamp
void CandleStream::advance(int64_t timestamp) {

  // Go past all the the candles before
  std::string line;
  for(int64_t i = currentCandle.timestamp; i < timestamp; ++i){
    if (!std::getline(file, line)) { };
  }

  // save cur candle
  if (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string item;

    Candle c;

    std::getline(ss, item, ','); c.timestamp = std::stoll(item);

    std::getline(ss, item, ','); c.open = std::stod(item);
    std::getline(ss, item, ','); c.high = std::stod(item);
    std::getline(ss, item, ','); c.low = std::stod(item);
    std::getline(ss, item, ','); c.close = std::stod(item);
    std::getline(ss, item, ','); c.volume = std::stod(item);

    currentCandle = c;
  } else {
    done = true;
  }

    // std::string line;
    // if (std::getline(file, line)) {
    //     std::stringstream ss(line);
    //     std::string item;

    //     Candle c;

    //     std::getline(ss, item, ','); c.timestamp = std::stoll(item);
    //     std::getline(ss, item, ','); c.open = std::stod(item);
    //     std::getline(ss, item, ','); c.high = std::stod(item);
    //     std::getline(ss, item, ','); c.low = std::stod(item);
    //     std::getline(ss, item, ','); c.close = std::stod(item);
    //     std::getline(ss, item, ','); c.volume = std::stod(item);

    //     currentCandle = c;
    // } else {
    //     done = true;
    // }
}
