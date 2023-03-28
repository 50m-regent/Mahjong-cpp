#ifndef MAHJONG_CONSTANTS_TILE_H
#define MAHJONG_CONSTANTS_TILE_H

#include <unordered_map>
#include <string>

namespace mahjong {

enum class Tile: uint64_t {
    NONE = 0,

    C1 = 1ull << 0,
    C2 = 1ull << 1,
    C3 = 1ull << 2,
    C4 = 1ull << 3,
    C5 = 1ull << 4,
    CR = 1ull << 5,
    CG = 1ull << 6,
    C6 = 1ull << 7,
    C7 = 1ull << 8,
    C8 = 1ull << 9,
    C9 = 1ull << 10,

    D1 = 1ull << 11,
    D2 = 1ull << 12,
    D3 = 1ull << 13,
    D4 = 1ull << 14,
    D5 = 1ull << 15,
    DR = 1ull << 16,
    DG = 1ull << 17,
    D6 = 1ull << 18,
    D7 = 1ull << 19,
    D8 = 1ull << 20,
    D9 = 1ull << 21,

    B1 = 1ull << 22,
    B2 = 1ull << 23,
    B3 = 1ull << 24,
    B4 = 1ull << 25,
    B5 = 1ull << 26,
    BR = 1ull << 27,
    BG = 1ull << 28,
    B6 = 1ull << 29,
    B7 = 1ull << 30,
    B8 = 1ull << 31,
    B9 = 1ull << 32,

    EAST  = 1ull << 33,
    SOUTH = 1ull << 34,
    WEST  = 1ull << 35,
    NORTH = 1ull << 36,

    WHITE = 1ull << 37,
    GREEN = 1ull << 38,
    RED   = 1ull << 39,

    SPRING = 1ull << 40,
    SUMMER = 1ull << 41,
    AUTUMN = 1ull << 42,
    WINTER = 1ull << 43,

    PLUM         = 1ull << 44,
    ORCHID       = 1ull << 45,
    CRYSANTHEMUM = 1ull << 46,
    BAMBOO       = 1ull << 47,
};

inline const std::unordered_map<Tile, std::string> TILE_DISPLAY = {
    {Tile::NONE, "None"},

    {Tile::C1, "C1"},
    {Tile::C2, "C2"},
    {Tile::C3, "C3"},
    {Tile::C4, "C4"},
    {Tile::C5, "C5"},
    {Tile::CR, "CR"},
    {Tile::CG, "CG"},
    {Tile::C6, "C6"},
    {Tile::C7, "C7"},
    {Tile::C8, "C8"},
    {Tile::C9, "C9"},

    {Tile::D1, "D1"},
    {Tile::D2, "D2"},
    {Tile::D3, "D3"},
    {Tile::D4, "D4"},
    {Tile::D5, "D5"},
    {Tile::DR, "DR"},
    {Tile::DG, "DG"},
    {Tile::D6, "D6"},
    {Tile::D7, "D7"},
    {Tile::D8, "D8"},
    {Tile::D9, "D9"},

    {Tile::B1, "B1"},
    {Tile::B2, "B2"},
    {Tile::B3, "B3"},
    {Tile::B4, "B4"},
    {Tile::B5, "B5"},
    {Tile::BR, "BR"},
    {Tile::BG, "BG"},
    {Tile::B6, "B6"},
    {Tile::B7, "B7"},
    {Tile::B8, "B8"},
    {Tile::B9, "B9"},

    {Tile::EAST,  "WE"},
    {Tile::SOUTH, "WS"},
    {Tile::WEST,  "WW"},
    {Tile::NORTH, "WN"},
    
    {Tile::WHITE, "SW"},
    {Tile::GREEN, "SG"},
    {Tile::RED,   "SR"},

    {Tile::SPRING, "FS"},
    {Tile::SUMMER, "FU"},
    {Tile::AUTUMN, "FA"},
    {Tile::WINTER, "FW"},

    {Tile::PLUM,         "FP"},
    {Tile::ORCHID,       "FO"},
    {Tile::CRYSANTHEMUM, "FC"},
    {Tile::BAMBOO,       "FB"},
};

inline const Tile operator~(const Tile tile) {
    return static_cast<Tile>(~static_cast<uint64_t>(tile));
}

template <typename T>
inline const T operator&(const T other, const Tile tile) {
    return other & static_cast<T>(tile);
}

template <typename T>
inline const T &operator&=(T &other, const Tile tile) {
    return other &= static_cast<T>(tile);
}

template <typename T>
inline const T &operator|=(T &other, const Tile tile) {
    return other |= static_cast<T>(tile);
}

}

#endif