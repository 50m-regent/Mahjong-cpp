#ifndef MAHJONG_PLAYERS_PLAYER_H
#define MAHJONG_PLAYERS_PLAYER_H

#include <iostream>

#include "tiles.h"
#include "constants/constants.h"

namespace mahjong {

class Player {
public:
    explicit Player(
        const uint32_t id,
        const uint32_t score
    ) : _id(id),
        _score(score) {}

    inline const Tiles get_tiles() const noexcept {
        return this->_tiles;
    }

    inline void pick(const Tile tile) noexcept {
        this->_tiles.add(tile);
    }

    inline void clear() noexcept {
        this->_tiles = Tiles();
        this->_river = Tiles();
    }

    virtual void discard() = 0;
    virtual ~Player() {}

protected:
    Tiles _tiles, _river;

private:
    const uint32_t _id;
    const uint32_t _score;
};

}

#endif