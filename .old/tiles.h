#ifndef MAHJONG_TILES_H
#define MAHJONG_TILES_H

#include <vector>
#include <iostream>

#include "constants/constants.h"

namespace mahjong {

class Tiles {
public:
    Tiles() : _tiles_bits(4, 0) {}

    explicit Tiles(
        const std::vector<Tile> tiles
    ) : _tiles_bits(4, 0) {
        for (const Tile tile: tiles) {
            this->add(tile);
        }
    }

    friend inline std::ostream &operator<<(std::ostream &os, const Tiles tiles) noexcept {
        os << "[";
        bool is_first = true;
        for (const Tile tile: tiles._tiles) {
            if (is_first) {
                is_first = false;
            } else {
                os << ",";
            }
            os << tile;
        }
        os << "]";

        return os;
    }

    static inline const uint8_t count(const Tiles tiles) noexcept {
        uint8_t sum = 0;
        for (const uint64_t tiles_bit: tiles._tiles_bits) {
            sum += Tiles::_count_bit<uint64_t>(tiles_bit);
        }

        return sum;
    }

    inline const Tile pop() noexcept {
        const Tile tile = this->_tiles.back();
        if (this->_remove(tile)) {
            this->_tiles.pop_back();
            return tile;
        }
        
        return Tile::NONE;
    }

    const bool add(const Tile tile) {
        assert (1 == Tiles::_count_bit<Tile>(tile));

        if (this->_tiles_bits[3] & tile) {
            return false;
        }

        this->_tiles.push_back(tile);
        for (uint8_t i = 3; i > 0; --i) {
            if (this->_tiles_bits[i - 1] & tile) {
                this->_tiles_bits[i] |= tile;
                return true;
            }
        }

        this->_tiles_bits[0] |= tile;
        return true;
    }

private:
    const bool _remove(const Tile tile) {
        assert (1 == Tiles::_count_bit<Tile>(tile));

        if (!(this->_tiles_bits[0] & tile)) {
            return false;
        }

        for (uint8_t i = 0; i < 3; ++i) {
            if (!((this->_tiles_bits[i + 1] & tile))) {
                this->_tiles_bits[i] &= ~tile;
                return true;
            }
        }

        this->_tiles_bits[3] &= ~tile;
        return true;
    }

    template <typename T>
    static inline const uint8_t _count_bit(T tiles) noexcept {
        uint64_t count = static_cast<uint64_t>(tiles);
        count = (count & 0x5555'5555'5555'5555ull) + ((count >>  1) & 0x5555'5555'5555'5555ull);
        count = (count & 0x3333'3333'3333'3333ull) + ((count >>  2) & 0x3333'3333'3333'3333ull);
        count = (count & 0x0f0f'0f0f'0f0f'0f0full) + ((count >>  4) & 0x0f0f'0f0f'0f0f'0f0full);
        count = (count & 0x00ff'00ff'00ff'00ffull) + ((count >>  8) & 0x00ff'00ff'00ff'00ffull);
        count = (count & 0x0000'ffff'0000'ffffull) + ((count >> 16) & 0x0000'ffff'0000'ffffull);
        count = (count & 0x0000'0000'ffff'ffffull) + ((count >> 32) & 0x0000'0000'ffff'ffffull);
        return static_cast<uint8_t>(count);
    }

    std::vector<Tile> _tiles;
    std::vector<uint64_t> _tiles_bits;
};

}

#endif