// data_loader.hpp
#pragma once
#include <vector>
#include <string>
#include "CandleStream.hpp"

std::unordered_map<std::string, std::unique_ptr<CandleStream>> getCandleStreams(const std::vector<std::string>& symbols);
