#include "data_loader.cpp"
#include "strategy_loader.cpp"

// JUST COPY PASTED FROM BINACE FETCHER cpp
const std::vector<std::string> loadTopSymbols(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
      std::cerr << "Failed to open file: " << filename << std::endl;
      return {};
  }
  std::vector<std::string> symbols;
  std::string line;
  while (std::getline(file, line)) {
    if (!line.empty()) {
      symbols.push_back(line);
    }
  }
  return symbols;
}

void backtest() {
  std::vector<std::string> symbols = loadTopSymbols("./data/top50.txt");
  std::unordered_map<std::string, std::unique_ptr<CandleStream>> candles = getCandleStream


  // Bring in the candle data

  // Bring in the strategy data

  // Go through each timestamp in strategy vector
  // Find all positions to buy, sell, hold (currently only works with binary signals)

}
