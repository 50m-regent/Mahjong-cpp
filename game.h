#pragma once

#include <vector>
#include <iostream>

#include "players.h"
#include "constants.h"
#include "internal.h"

namespace mahjong {

class Mahjong {
private:
    const constants::Wind type;
    const std::vector<players::Player> all_players;
    const uint32_t score_threshold;

    constants::Wind field_wind;
    uint8_t round_count;
    std::pair<uint8_t, uint8_t> stack;
    std::vector<constants::Tile> dora_indicators;
    std::vector<constants::Tile> wall_tiles;
    std::vector<constants::Tile> dead_tiles;
    constants::Wind turn_wind;

    const internal::RoundResult play_round() const;
    const void initialize_round(
        const internal::RoundResult
    ) const;
    const bool has_player_reached_threshold() const;
    const bool has_dead_player() const;
public:
    explicit Mahjong(
        const constants::Wind,
        const std::vector<players::Player>,
        const uint32_t
    );

    const void play() const;
    const bool is_end() const;

    friend std::ostream& operator<<(
        std::ostream&,
        const Mahjong
    );
};

}