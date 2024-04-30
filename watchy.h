#include <map>

static const std::string clear_night = "\U000F0594";
static const std::string cloudy = "\U000F0590";
static const std::string haze = "\U000F0F30";
static const std::string exceptional = "\U000F0026";
static const std::string fog = "\U000F0591";
static const std::string hail = "\U000F0592";
static const std::string lightning = "\U000F0593";
static const std::string lightning_rainy = "\U000F067E";
static const std::string partly_cloudy = "\U000F0595";
static const std::string pouring = "\U000F0596";
static const std::string rainy = "\U000F0597";
static const std::string snowy = "\U000F0598";
static const std::string snowy_rainy = "\U000F067F";
static const std::string sunny = "\U000F0599";
static const std::string windy = "\U000F059D";
static const std::string windy_variant = "\U000F059E";

static const std::string night = "\U000F0594";
static const std::string night_partly_cloudy = "\U000F0F31";

// https://openweathermap.org/weather-conditions#Weather-Condition-Codes-2

std::map<int, std::string> weather_icon_map{
    {0, exceptional},

    {200, lightning_rainy}, // thunderstorm with light rain
    {201, lightning_rainy}, // thunderstorm with rain
    {202, lightning_rainy}, // thunderstorm with heavy rain
    {210, lightning},       // light thunderstorm
    {211, lightning},       // thunderstorm
    {212, lightning},       // heavy thunderstorm
    {221, lightning},       // ragged thunderstorm
    {230, lightning_rainy}, // thunderstorm with light drizzle
    {231, lightning_rainy}, // thunderstorm with drizzle
    {232, lightning_rainy}, // thunderstorm with heavy drizzle

    {300, rainy}, // light intensity drizzle
    {301, rainy}, // drizzle
    {302, rainy}, // heavy intensity drizzle
    {310, rainy}, // light intensity drizzle rain
    {311, rainy}, // drizzle rain
    {312, rainy}, // heavy intensity drizzle rain
    {313, rainy}, // shower rain and drizzle
    {314, rainy}, // heavy shower rain and drizzle
    {321, rainy}, // shower drizzle

    {500, rainy},   // light rain
    {501, pouring}, // moderate rain
    {502, pouring}, // heavy intensity rain
    {503, pouring}, // very heavy rain
    {504, pouring}, // extreme rain
    {511, hail},    // freezing rain
    {520, rainy},   // light intensity shower rain
    {521, rainy},   // shower rain
    {522, pouring}, // heavy intensity shower rain
    {531, rainy},   // ragged shower rain

    {600, snowy},       // light snow
    {601, snowy},       // snow
    {602, snowy},       // heavy snow
    {611, snowy},       // sleet
    {612, snowy},       // light shower sleet
    {613, snowy},       // shower sleet
    {615, snowy_rainy}, // light rain and snow
    {616, snowy_rainy}, // rain and snow
    {620, snowy},       // light shower snow
    {621, snowy},       // shower snow
    {622, snowy},       // heavy shower snow 	13d

    {701, fog},   // mist
    {711, fog},   // smoke
    {721, haze},  // haze
    {731, fog},   // sand/dust whirls
    {741, fog},   // fog
    {751, fog},   // sand
    {761, fog},   // dust
    {762, fog},   // volcanic ash
    {771, windy}, // squalls
    {781, windy}, // tornado

    {800, sunny}, // clear

    {801, partly_cloudy}, // few clouds: 11-25%
    {802, partly_cloudy}, // scattered clouds: 25-50%
    {803, partly_cloudy}, // broken clouds: 51-84%
    {804, cloudy},        // overcast clouds: 85-100%

    {1800, night},               // clear
    {1801, night_partly_cloudy}, // few clouds: 11-25%
    {1802, night_partly_cloudy}, // scattered clouds: 25-50%
    {1803, night_partly_cloudy}, // broken clouds: 51-84%
    {1804, cloudy},              // overcast clouds: 85-100%
};

int weatherCode(int code, const std::string &icon)
{
  // ESP_LOGE("cal", "%d, %s, %c", code, icon, icon.back());
  if (code >= 800 && code < 900 && !icon.empty() && icon.back() == 'n')
  {
    return 1000 + code;
  }
  return code;
}

int getWeatherCodeIndex(int quadrant, int h24)
{
  const int h = h24 % 12;
  int offset = 0;
  if (h < 3)
  {
    offset = 0;
  }
  else if (h < 6)
  {
    offset = 3;
  }
  else if (h < 9)
  {
    offset = 2;
  }
  else if (h < 12)
  {
    offset = 1;
  }
  return (offset + quadrant) % 4;
}

int rotateWeatherCode(int quadrant, int h24, int a, int b, int c, int d)
{
  int i = getWeatherCodeIndex(quadrant, h24);
  if (i == 0)
  {
    return a;
  }
  if (i == 1)
  {
    return b;
  }
  if (i == 2)
  {
    return c;
  }
  if (i == 3)
  {
    return d;
  }
  return 0;
}

int getClkXY(int hour, int xy)
{
  double hr = (hour / 12.0 * 360.0 - 90.0) * (M_PI / 180.0);
  return 100 + 90 * (xy == 0 ? cos(hr) : sin(hr));
}

int getClkX(int hour)
{
  return getClkXY(hour, 0);
}

int getClkY(int hour)
{
  return getClkXY(hour, 1);
}