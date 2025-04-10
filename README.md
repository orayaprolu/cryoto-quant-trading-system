# Quant Trading System v2 (C++ Core + Python Dashboard)

This is a modular, performant trading system built with **C++** for quant-style trading strategy development, and **Python** for visualization and analytics.

The goal is to demonstrate strong systems engineering skills, familiarity with quant research workflows, and the ability to build a realistic, production-oriented trading infrastructure — with a focus on performance, modularity, and clarity.

## 🔧 Architecture Overview

- **Data Ingestion**: Real-time and historical data fetched from crypto exchanges via REST and WebSocket APIs.
- **Strategy Engine**: Modular plug-and-play architecture to test multiple signal-generation strategies.
- **Backtesting Engine**: Historical data simulation with configurable parameters like latency, slippage, and commissions.
- **Execution Layer**: Simulated (paper) trading and optional real execution support.
- **Risk Management**: Position sizing, stop loss, exposure tracking, drawdown rules.
- **Performance Logging**: Every trade and system action is logged for review and debugging.
- **Dashboard**: Python-based dashboard (Streamlit or Dash) for visualizing performance, risk, trades, and PnL.

## 🧱 Tech Stack

| Component        | Tech                                               |
|------------------|----------------------------------------------------|
| Core Logic       | C++17 (Build with CMake)                          |
| Networking       | `libcurl` for REST, `websocketpp` for WebSockets  |
| JSON Parsing     | `nlohmann/json`                                    |
| Logging          | `spdlog`                                           |
| Data Format      | CSV (output to Python dashboard)                  |
| Dashboard        | Streamlit or Dash (Python)                         |

## 🔁 System Flow

[ Exchange API ] → [ C++ Ingestion Layer ] → [ Strategy Engine ]
↓
[ Backtesting ]
↓
[ Execution Logic ]
↓
[ Logging + CSV ]
↓
[ Python Dashboard (Live/Backtest View) ]

## 📂 Folder Structure

/src
main.cpp
ingest/
strategy/
backtest/
execution/
risk/
utils/
/include
(Headers)
/data
(Historical data, CSV output)
/dashboard
(Python Streamlit/Dash app)
/tests
README.md
CMakeLists.txt

---



