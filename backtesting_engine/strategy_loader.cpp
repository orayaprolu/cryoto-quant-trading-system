#include <cstdint>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

#include "strategy_loader.hpp"


std::vector<CoinWeight> createCoinWeightVector(std::string& str_coin_weight) {
  if (str_coin_weight.length() <= 2) {
    return std::vector<CoinWeight>();
  }

  std::vector<CoinWeight> ret_list;

  // Remove the leading/ending quotes and brackets
  str_coin_weight = str_coin_weight.substr(2, str_coin_weight.length() - 2);

  // Make a stream of coin and weight pairs seperated by commas
  auto ss = std::stringstream(str_coin_weight);
  std::string line;

  // Go through every coin weight pair
  while (std::getline(ss, line, ',')) {
    // Remove single quotes from coin weight pair
    line = line.substr(1, line.length() - 1);
    auto coin_weight_ss = std::stringstream(line);
    std::string item;

    auto cw = CoinWeight();

    std::getline(coin_weight_ss, cw.coin, ':');
    std::getline(coin_weight_ss, item); cw.weight = std::stod(item);
    ret_list.push_back(cw);
  }

  return ret_list;




}

// A vector here might be inefficient when I try and load in a shit
// ton of like 1m candles on BTC. Must be a better way to do this. I
// am thinking like buffered reading from a file which would minimize the
// file opens and reads. For now its fine for vector tho

StrategyStream load_strategy(const std::string& filepath) {
  std::ifstream file;
  file.open(filepath);

  StrategyStream ret;

  std::string line;
  std::getline(file, line); // Throws away header

  // Get the first line
  if (std::getline(file, line)) {
    auto ss = std::stringstream(line);
    std::string item;

    std::vector<CoinWeight> signals;

    std::getline(ss, item, ','); ret.first_timestamp = std::stoll(item);
    std::getline(ss, item); signals = createCoinWeightVector(item);
    ret.signals.push_back(signals);
  }

  // Get the second line
  if (std::getline(file, line)) {
    auto ss = std::stringstream(line);
    std::string item;

    std::vector<CoinWeight> signals;

    std::getline(ss, item, ','); ret.interval_in_ms = std::stoll(item) - ret.first_timestamp;
    std::getline(ss, item); signals = createCoinWeightVector(item);
    ret.signals.push_back(signals);
  }

  // Get remaining lines
  while (std::getline(file, line)) {
    auto ss = std::stringstream(line);
    std::string item;

    std::vector<CoinWeight> signals;

    std::getline(ss, item, ',');
    std::getline(ss, item); signals = createCoinWeightVector(item);
    ret.signals.push_back(signals);
  }

  return ret;
}

// int main() {
//   StrategyStream s = load_strategy("./strategies/loose_pants_trend_following");
//   for (auto signal_list : s.signals) {
//     if (signal_list.empty()) {
//       std::cout << "No positions on this timestamp";
//     } else {
//       for (auto signal : signal_list) {
//         std::cout << signal.coin << ":" << signal.weight << ", ";
//       }
//     }

//     std::cout << std::endl;
//     std::cout << std::endl;
//     std::cout << std::endl;
//     std::cout << std::endl;
//   }
// }
