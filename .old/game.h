#ifndef MAHJONG_GAME_H
#define MAHJONG_GAME_H

#include <vector>
#include <iostream>
#include <memory>

#include "round.h"
#include "players/players.h"
#include "constants/constants.h"

namespace mahjong {

class Mahjong {
public:
    explicit Mahjong(
        const std::vector<std::shared_ptr<Player>> players,
        const Wind end_wind,
        const bool has_red,
        std::ostream &os
    ) : _players(players),
        _end_wind(end_wind),
        _has_red(has_red),
        _os(os),
        _round(Wind::EAST, 1, 0, 0, players, has_red) {}

    void play() noexcept {
        while (!this->_end()) {
            this->_round.play(this->_os);
            this->_round.proceed();
        }
    }

private:
    const inline bool _end() const noexcept {
        return this->_round.get_wind() > this->_end_wind || Wind::NONE == this->_round.get_wind();
    }

    const std::vector<std::shared_ptr<Player>> _players;
    const Wind _end_wind;
    const bool _has_red;
    std::ostream &_os;

    Round _round;
};

}

#endif