#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>

#include "Candle.hpp"
#include "CandleStream.hpp"

std::vector<std::string> loadTopSymbols(const std::string& filename) {
    std::vector<std::string> symbols;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            symbols.push_back(line);
        }
    }
    return symbols;
}

std::vector<std::unique_ptr<CandleStream>> getCandleStreams(const std::vector<std::string>& symbols) {
    std::vector<std::unique_ptr<CandleStream>> streams;
    for (const auto& symbol : symbols) {
        streams.push_back(std::make_unique<CandleStream>("../data/" + symbol + "USDT_1d.csv"));
    }
    return streams;
}



int main() {
    // std::string file_path = "../data/BTCUSDT_1m.csv";
    // const auto candle_vector = loadCandles(file_path);
    // logCandleVector(candle_vector);
    auto symbols = std::vector<std::string>{"BTC", "ETH"};
    std::vector<std::unique_ptr<CandleStream>> candle_streams = getCandleStreams(symbols);

    std::cout << "PEEP " << candle_streams[0]->current().toString() << std::endl;
    candle_streams[0]->advance();
    std::cout << "PEEP " << candle_streams[0]->current().toString() << std::endl;

    return 0;
}
