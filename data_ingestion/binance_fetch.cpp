#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

// For conveniencez
using json = nlohmann::json;

// This function stores the response from libcurl
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void binance_data_to_csv(std::string symbol, std::string interval, const int limit = 100) {
    symbol += "USDT";

    std::string url = "https://api.binance.com/api/v3/klines?symbol=" + symbol +
                      "&interval=" + interval + "&limit=" + std::to_string(limit);

    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Write callback
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        // Pass our string to store the result
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Perform the request
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << "\n";
        } else {
            // Parse the JSON response
            json response = json::parse(readBuffer);

            // Write to CSV
            std::ofstream outFile("../data/" + symbol + "_" + interval + ".csv");
            outFile << "OpenTime,Open,High,Low,Close,Volume\n";

            for (const auto& candle : response) {
                outFile
                    << candle[0].get<int64_t>() << ","   // Open time
                    << std::stod(candle[1].get<std::string>()) << ","   // Open
                    << std::stod(candle[2].get<std::string>()) << ","   // High
                    << std::stod(candle[3].get<std::string>()) << ","   // Low
                    << std::stod(candle[4].get<std::string>()) << ","   // Close
                    << std::stod(candle[5].get<std::string>()) << "\n"; // Volume
            }

            std::cout << "Saved " << response.size() << " candles to data/" + symbol + "_" + interval + ".csv\n";
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main() {
    return 0;
}
