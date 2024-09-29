int calcSleepTimeSeconds(bool powerSavingMode, float clockIntervalMinutes, esphome::ESPTime now)
{
  const int x = powerSavingMode ? 10 : int(clockIntervalMinutes);
  if (x == 0)
  {
    return 0;
  }
  else
  {
    return ((x - (now.minute % x)) * 60 - now.second);
  }
}

int getClkXY(int hour, int xy)
{
  double hr = (hour / 12.0 * 360.0 - 90.0) * (M_PI / 180.0);
  return 100 + 90 * (xy == 0 ? cos(hr) : sin(hr));
};

int getClkX(int hour)
{
  return getClkXY(hour, 0);
};

int getClkY(int hour)
{
  return getClkXY(hour, 1);
};
