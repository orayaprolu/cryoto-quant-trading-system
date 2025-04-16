#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <unordered_map>

#include "Candle.hpp"
#include "CandleStream.hpp"
#include "data_loader.hpp"

std::unordered_map<std::string, std::unique_ptr<CandleStream>> getCandleStreams(const std::vector<std::string>& symbols) {
  std::unordered_map<std::string, std::unique_ptr<CandleStream>> streams;
  for (const auto& symbol : symbols) {
    streams[symbol] = std::make_unique<CandleStream>("./data/" + symbol + "USDT_1d.csv");
  }
  return streams;
}



// int main() {
//     // std::string file_path = "../data/BTCUSDT_1m.csv";
//     // const auto candle_vector = loadCandles(file_path);
//     // logCandleVector(candle_vector);
//     auto symbols = std::vector<std::string>{"BTC", "ETH"};
//     std::unordered_map<std::string, std::unique_ptr<CandleStream>> candle_streams = getCandleStreams(symbols);

//     std::cout << "PEEP " << candle_streams["BTC"]->current().toString() << std::endl;
//     candle_streams["BTC"]->advance();
//     std::cout << "PEEP " << candle_streams["BTC"]->current().toString() << std::endl;

//     return 0;
// }
