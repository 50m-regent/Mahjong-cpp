#ifndef MAHJONG_CONSTANTS_WIND_H
#define MAHJONG_CONSTANTS_WIND_H

#include <unordered_map>
#include <string>

namespace mahjong {

enum class Wind: uint8_t {
    NONE,

    EAST,
    SOUTH,
    WEST,
    NORTH,
};

template <typename T>
inline const T operator-(const Wind wind, const T other) noexcept {
    return static_cast<T>(wind) - other;
}

inline const std::unordered_map<Wind, Wind> NEXT_WIND = {
    {Wind::NONE, Wind::NONE},

    {Wind::EAST,  Wind::SOUTH},
    {Wind::SOUTH, Wind::WEST},
    {Wind::WEST,  Wind::NORTH},
    {Wind::NORTH, Wind::EAST},
};

inline const std::unordered_map<Wind, std::string> WIND_DISPLAY = {
    {Wind::NONE, "None"},

    {Wind::EAST,  "east"},
    {Wind::SOUTH, "south"},
    {Wind::WEST,  "west"},
    {Wind::NORTH, "north"},
};

}

#endif