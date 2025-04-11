#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

// For conveniencez
using json = nlohmann::json;

// This function stores the response from libcurl
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    const std::string symbol = "BTCUSDT";
    const std::string interval = "1m";
    const int limit = 100;

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
            std::ofstream outFile("../data/BTCUSDT_1m.csv");
            outFile << "OpenTime,Open,High,Low,Close,Volume\n";

            for (const auto& candle : response) {
                outFile
                    << candle[0] << ","   // Open time (ms)
                    << candle[1] << ","   // Open price
                    << candle[2] << ","   // High price
                    << candle[3] << ","   // Low price
                    << candle[4] << ","   // Close price
                    << candle[5] << "\n"; // Volume
            }

            std::cout << "Saved " << response.size() << " candles to data/BTCUSDT_1m.csv\n";
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}
