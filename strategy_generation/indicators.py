import pandas as pd

def twenty_day_high_within_lookback(ser: pd.Series, lookback: int):
    """
    Returns a binary signal Series: 1 if the max close of previous `lookback` periods >= the max close of previous 20 days, 0 otherwise.
    """
    twenty_day_high = ser.rolling(window=20).max()
    lookback_day_high = ser.rolling(window=lookback).max()


    # > gives boolean series, astype(int) converts every val in boolean series to an int equivalent
    signal = (lookback_day_high >= twenty_day_high).astype(int)
    return signal

def twenty_day_low_within_lookback(ser: pd.Series, lookback: int):
    """
    Returns a binary signal Series: -1 if the min close of previous `lookback` periods <= the min close of previous 20 days, 0 otherwise.
    """
    twenty_day_low = ser.rolling(window=20).min()
    lookback_day_low = ser.rolling(window=lookback).min()


    # < gives boolean series, astype(int) converts every val in boolean series to an int equivalent
    signal = (lookback_day_low <= twenty_day_low).astype(int) * -1
    return signal
