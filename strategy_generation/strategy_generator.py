import pandas as pd
import os
from . import indicators


def generate_signals():
  df = apply_strategy();

  result = {}
  for ts, row in df.iterrows():
    signal_dict = {coin: signal for coin, signal in row.items() if pd.notna(signal) and signal != 0}
    signal_list = [f"{coin}:{signal}" for coin, signal in signal_dict.items()]
    result[ts] = signal_list

  out_df = pd.DataFrame([
      {"OpenTime": ts, "Signals": signals}
      for ts, signals in result.items()
  ])
  out_df.set_index("OpenTime", inplace=True)
  out_df.to_csv('./strategies/loose_pants_trend_following')


# Take the top 50 coins and gather a df joined on their timestamp
def apply_strategy() -> pd.DataFrame:
  base_dir = os.path.dirname(os.path.abspath(__file__))
  top_50_path = os.path.join(base_dir, '..', 'data', 'top50.txt')

  coins = []
  with open(top_50_path, 'r') as f:
    coins = f.read().splitlines()

  combined_df = pd.DataFrame()
  for coin in coins[:11]:
    signal = loose_pants_trend(coin)
    combined_df[coin] = signal

  return combined_df

# Must return a df with a col called signal in my framework !!
def loose_pants_trend(coin: str, lookback: int = 5) -> pd.Series:
  """
  Strategy: Enter position when close is highest in `lookback` period.
  Must return a Series with a 'signal' column.
  """

  base_dir = os.path.dirname(os.path.abspath(__file__))
  csv_path = os.path.join(base_dir, '..', 'data', f'{coin}USDT_1d.csv')
  if not os.path.exists(csv_path):
    print(f"couldn't find {coin}'s CSV")

  df = pd.read_csv(csv_path)
  df.set_index('OpenTime', inplace=True)
  ser = pd.Series(df['Close'])

  # Compute 20 day high signals
  long_signal = indicators.twenty_day_high_within_lookback(ser, lookback)
  short_signal = indicators.twenty_day_low_within_lookback(ser, lookback)
  signal: pd.Series  = (long_signal + short_signal).shift(1)

  return signal

generate_signals()

# loose_pants_strat_df = apply_to_all()
# loose_pants_strat_df.to_csv('./strategies/loose_pants_trend_following')


  # # Step 3: Compute log returns and EW volatility
  # df['log_return'] = np.log(df['close'] / df['close'].shift(1))
  # df['recent_volatility'] = df['log_return'].ewm(span=recent_sd_daily_returns, adjust=False).std()

  # # Step 4: Volatility-standardize
  # df['volatility_standardized_forecast'] = df['raw_forecast'] / df['recent_volatility']

  # # Step 5: Forecast scalar to target E[|x|] = 10
  # forecast_scalar = 10 / df['volatility_standardized_forecast'].abs().mean()
  # df['volatility_standardized_forecast'] *= forecast_scalar

  # # # Step 6: Clip extreme values
  # df['volatility_standardized_forecast'] = np.clip(df['volatility_standardized_forecast'], -20, 20)
