#include "CandleStream.hpp"
#include <cstdint>
#include <iostream>
#include <ostream>
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

  // While our current candle's time stamp is less than targeted timestamp, keep going
  std::string line;
  while (currentCandle.timestamp < timestamp) {
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
      return;
    }
  }

  if (currentCandle.timestamp != timestamp) {
    std::cout << "timestamp out of synch somehow" << std::endl;
  }
}
