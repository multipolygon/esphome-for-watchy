#include <map>
// #include "mdi.h"

// https://openweathermap.org/weather-conditions#Weather-Condition-Codes-2

std::map<int, const char *> weatherIcons{
    {0, mdiAlert},                       // Exception
                                         //// STORM ////
    {200, mdiWeatherLightningRainy},     // thunderstorm with light rain
    {201, mdiWeatherLightningRainy},     // thunderstorm with rain
    {202, mdiWeatherLightningRainy},     // thunderstorm with heavy rain
    {210, mdiWeatherLightning},          // light thunderstorm
    {211, mdiWeatherLightning},          // thunderstorm
    {212, mdiWeatherLightning},          // heavy thunderstorm
    {221, mdiWeatherLightning},          // ragged thunderstorm
    {230, mdiWeatherLightningRainy},     // thunderstorm with light drizzle
    {231, mdiWeatherLightningRainy},     // thunderstorm with drizzle
    {232, mdiWeatherLightningRainy},     // thunderstorm with heavy drizzle
                                         //// DRIZZLE ////
    {300, mdiWeatherRainy},              // light intensity drizzle
    {301, mdiWeatherRainy},              // drizzle
    {302, mdiWeatherPouring},            // heavy intensity drizzle
    {310, mdiWeatherRainy},              // light intensity drizzle rain
    {311, mdiWeatherRainy},              // drizzle rain
    {312, mdiWeatherPouring},            // heavy intensity drizzle rain
    {313, mdiWeatherRainy},              // shower rain and drizzle
    {314, mdiWeatherPouring},            // heavy shower rain and drizzle
    {321, mdiWeatherRainy},              // shower drizzle
                                         //// RAIN ////
    {500, mdiWeatherRainy},              // light rain
    {501, mdiWeatherRainy},              // moderate rain
    {502, mdiWeatherPouring},            // heavy intensity rain
    {503, mdiWeatherPouring},            // very heavy rain
    {504, mdiWeatherPouring},            // extreme rain
    {511, mdiWeatherHail},               // freezing rain
    {520, mdiWeatherPartlyRainy},        // light intensity shower rain
    {521, mdiWeatherPartlyRainy},        // shower rain
    {522, mdiWeatherPartlyRainy},        // heavy intensity shower rain
    {531, mdiWeatherPartlyRainy},        // ragged shower rain
                                         //// SNOW ////
    {600, mdiWeatherPartlySnowy},        // light snow
    {601, mdiWeatherSnowy},              // snow
    {602, mdiWeatherSnowyHeavy},         // heavy snow
    {611, mdiWeatherSnowyRainy},         // sleet
    {612, mdiWeatherPartlySnowyRainy},   // light shower sleet
    {613, mdiWeatherSnowyRainy},         // shower sleet
    {615, mdiWeatherPartlySnowyRainy},   // light rain and snow
    {616, mdiWeatherSnowyRainy},         // rain and snow
    {620, mdiWeatherPartlySnowyRainy},   // light shower snow
    {621, mdiWeatherSnowyRainy},         // shower snow
    {622, mdiWeatherSnowyHeavy},         // heavy shower snow 	13d
                                         //// ATMOSPHERE ////
    {701, mdiWeatherFog},                // mist
    {711, mdiWeatherFog},                // smoke
    {721, mdiWeatherHazy},               // haze
    {731, mdiWeatherDust},               // sand/dust whirls
    {741, mdiWeatherFog},                // fog
    {751, mdiWeatherDust},               // sand
    {761, mdiWeatherDust},               // dust
    {762, mdiWeatherHazy},               // volcanic ash
    {771, mdiWeatherWindy},              // squalls
    {781, mdiWeatherTornado},            // tornado
                                         //// SUNNY ////
    {800, mdiWeatherSunny},              // clear
    {801, mdiWeatherSunny},              // few clouds: 11-25%
    {802, mdiWeatherPartlyCloudy},       // scattered clouds: 25-50%
    {803, mdiWeatherPartlyCloudy},       // broken clouds: 51-84%
    {804, mdiWeatherCloudy},             // overcast clouds: 85-100%
                                         /////////// NIGHT ///////////
                                         //// STORM ////
    {1200, mdiWeatherLightningRainy},    // thunderstorm with light rain
    {1201, mdiWeatherLightningRainy},    // thunderstorm with rain
    {1202, mdiWeatherLightningRainy},    // thunderstorm with heavy rain
    {1210, mdiWeatherLightning},         // light thunderstorm
    {1211, mdiWeatherLightning},         // thunderstorm
    {1212, mdiWeatherLightning},         // heavy thunderstorm
    {1221, mdiWeatherLightning},         // ragged thunderstorm
    {1230, mdiWeatherLightningRainy},    // thunderstorm with light drizzle
    {1231, mdiWeatherLightningRainy},    // thunderstorm with drizzle
    {1232, mdiWeatherLightningRainy},    // thunderstorm with heavy drizzle
                                         //// DRIZZLE ////
    {1300, mdiWeatherRainy},             // light intensity drizzle
    {1301, mdiWeatherRainy},             // drizzle
    {1302, mdiWeatherPouring},           // heavy intensity drizzle
    {1310, mdiWeatherRainy},             // light intensity drizzle rain
    {1311, mdiWeatherRainy},             // drizzle rain
    {1312, mdiWeatherPouring},           // heavy intensity drizzle rain
    {1313, mdiWeatherRainy},             // shower rain and drizzle
    {1314, mdiWeatherPouring},           // heavy shower rain and drizzle
    {1321, mdiWeatherRainy},             // shower drizzle
                                         //// RAIN ////
    {1500, mdiWeatherRainy},             // light rain
    {1501, mdiWeatherRainy},             // moderate rain
    {1502, mdiWeatherPouring},           // heavy intensity rain
    {1503, mdiWeatherPouring},           // very heavy rain
    {1504, mdiWeatherPouring},           // extreme rain
    {1511, mdiWeatherHail},              // freezing rain
    {1520, mdiWeatherRainy},             // light intensity shower rain
    {1521, mdiWeatherRainy},             // shower rain
    {1522, mdiWeatherRainy},             // heavy intensity shower rain
    {1531, mdiWeatherRainy},             // ragged shower rain
                                         //// SNOW ////
    {1600, mdiWeatherSnowy},             // light snow
    {1601, mdiWeatherSnowy},             // snow
    {1602, mdiWeatherSnowyHeavy},        // heavy snow
    {1611, mdiWeatherSnowyRainy},        // sleet
    {1612, mdiWeatherSnowyRainy},        // light shower sleet
    {1613, mdiWeatherSnowyRainy},        // shower sleet
    {1615, mdiWeatherSnowyRainy},        // light rain and snow
    {1616, mdiWeatherSnowyRainy},        // rain and snow
    {1620, mdiWeatherSnowyRainy},        // light shower snow
    {1621, mdiWeatherSnowyRainy},        // shower snow
    {1622, mdiWeatherSnowyHeavy},        // heavy shower snow 	13d
                                         //// ATMOSPHERE ////
    {1701, mdiWeatherFog},               // mist
    {1711, mdiWeatherFog},               // smoke
    {1721, mdiWeatherHazy},              // haze
    {1731, mdiWeatherDust},              // sand/dust whirls
    {1741, mdiWeatherFog},               // fog
    {1751, mdiWeatherDust},              // sand
    {1761, mdiWeatherDust},              // dust
    {1762, mdiWeatherHazy},              // volcanic ash
    {1771, mdiWeatherWindy},             // squalls
    {1781, mdiWeatherTornado},           // tornado
                                         //// SUNNY ////
    {1800, mdiWeatherNight},             // clear
    {1801, mdiWeatherNight},             // few clouds: 11-25%
    {1802, mdiWeatherNightPartlyCloudy}, // scattered clouds: 25-50%
    {1803, mdiWeatherNightPartlyCloudy}, // broken clouds: 51-84%
    {1804, mdiWeatherCloudy},            // overcast clouds: 85-100%
};

int weatherCode(int code, const std::string &daynight)
{
  // ESP_LOGE("cal", "%d, %s, %c", code, icon, icon.back());
  if (!daynight.empty() && daynight.back() == 'n')
  {
    return 1000 + code;
  }
  return code;
};

int rotateWeatherCode(int quadrant, int h24)
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
};

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

int getClkXY24(int hour, int xy)
{
  double hr = ((hour % 24) / 24.0 * 360.0 + 90.0) * (M_PI / 180.0);
  return 100 + 90 * (xy == 0 ? cos(hr) : sin(hr));
};

int getClkX24(int hour)
{
  return getClkXY24(hour, 0);
};

int getClkY24(int hour)
{
  return getClkXY24(hour, 1);
};

const char *sky[] = {
    mdiStarOutline,
    mdiStarShootingOutline,
    mdiCreationOutline,
    mdiHelicopter,
    mdiAirballoon,
    mdiBird,
    mdiSpaceInvaders,
    mdiSpaceStation,
    mdiUfoOutline,
    mdiSatelliteVariant,
    mdiRocketLaunch};
const int skyLen = 11;

const char *city[] = {
    mdiCity,
    mdiCityVariant,
    mdiOfficeBuilding,
    mdiCity,
    mdiCityVariant,
    mdiOfficeBuilding,
    mdiCity,
    mdiCityVariant,
    mdiCityVariant,
    mdiOfficeBuilding,
    mdiCity,
    mdiCity,
    mdiCityVariant,
    mdiOfficeBuilding,
    mdiCity,
    mdiCityVariant,
    mdiOfficeBuilding,
    mdiCity,
    mdiCityVariant,
    mdiOfficeBuilding,
    mdiCastle,
    mdiGoogleDownasaur,
    mdiHospitalBuilding,
    mdiPineTree,
};
const int cityLen = 24;

std::map<int, const char *>
    significantDatesIcons{
        // https://www.timeanddate.com/holidays/world/
        // https://www.timeanddate.com/holidays/un/
        {101, mdiPartyPopper},
        {121, mdiSchool},
        {214, mdiHeart},
        {229, mdiDebugStepOver},
        {303, mdiElephant},
        {320, mdiEmoticonHappyOutline},
        {320, mdiEmoticonHappyOutline},
        {321, mdiForest},
        {322, mdiWater},
        {401, mdiDonkey},
        {412, mdiRocketLaunch},
        {422, mdiEarth},
        {504, mdiDeathStarVariant},
        {508, mdiPlusThick},
        {512, mdiHospitalBuilding},
        {520, mdiBee},
        {601, mdiHumanMaleChild},
        {603, mdiBicycle},
        {620, mdiFerry},
        {823, mdiLinkBoxVariant},
        {915, mdiVote},
        {921, mdiPeace},
        {1005, mdiHumanMaleBoard},
        {1031, mdiHalloween},
        {1111, mdiMedal},
        {1120, mdiTeddyBear},
    };
