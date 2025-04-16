#pragma once

#include <vector>
#include <string>

struct CoinWeight {
  std::string coin;
  double weight;
};

struct StrategyStream {
  int64_t first_timestamp = -1;
  int64_t interval_in_ms = -1;
  std::vector<std::vector<CoinWeight>> signals;
};



StrategyStream load_strategy(const std::string& filepath);
