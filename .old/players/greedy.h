#ifndef MAHJONG_PLAYERS_GREEDY_H
#define MAHJONG_PLAYERS_GREEDY_H

#include "player.h"

namespace mahjong {

class GreedyPlayer: public Player {
public:
    explicit GreedyPlayer(
        const uint32_t id,
        const uint32_t score
    ) : Player(id, score) {}

    virtual void discard() noexcept override final {
        Player::_river.add(Player::_tiles.pop());
    }
};

}

#endif