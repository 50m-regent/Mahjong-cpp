#pragma once

#include <unordered_map>
#include <string>

namespace mahjong::constants {

enum class Wind: uint8_t {
    EAST,
    SOUTH,
    WEST,
    NORTH,
};

inline const std::unordered_map<Wind, std::string> WIND2STRING = {
    {Wind::EAST,  "East"},
    {Wind::SOUTH, "South"},
    {Wind::WEST,  "West"},
    {Wind::NORTH, "North"},
};

std::ostream& operator<<(
    std::ostream&,
    const Wind
);

}