#include "mahjong.h"

namespace mahjong {

Mahjong::Mahjong(
    const constants::Wind type,
    const std::vector<players::Player> all_players,
    const uint32_t score_threshold
) : type(type),
    all_players(all_players),
    score_threshold(score_threshold)
{
    this->field_wind  = constants::Wind::EAST;
    this->round_count = 1;
    this->stack       = {0, 0};

    this->initialize_tiles();
    this->turn_wind = constants::Wind::EAST;
}

const internal::RoundResult Mahjong::play_round() const {

}

const void Mahjong::initialize_round(
    const internal::RoundResult round_result
) const {
    
}

const bool Mahjong::has_player_reached_threshold() const {
    for (const players::Player player: this->all_players) {
        if (player.get_score() >= this->score_threshold) {
            return true;
        }
    }

    return false;
}

const bool Mahjong::has_dead_player() const {
    for (const players::Player player: this->all_players) {
        if (player.get_score() < 0) {
            return true;
        }
    }

    return false;
}

const void Mahjong::play() const {
    while (!this->is_end()) {
        const internal::RoundResult round_result = this->play_round();
        this->initialize_round(round_result);
    }
}

const bool Mahjong::is_end() const {
    return
        (
            this->has_player_reached_threshold() &&
            this->type < this->field_wind
        ) ||
        this->has_dead_player();
}

std::ostream& operator<<(
    std::ostream& ostream,
    const Mahjong game
) {
    ostream << "game type: "      << game.type            << std::endl;
    ostream << "field wind: "     << game.field_wind      << std::endl;
    ostream << "round count: "    << game.round_count     << std::endl;
    ostream << "stack: "          << game.stack.first     << " "
                                  << game.stack.second    << std::endl;

    ostream << "dora indicator: ";
    for (const constants::Tile tile: game.dora_indicators) {
        ostream << tile << ",";
    }
    ostream << std::endl;

    ostream << "wall: ";
    for (const constants::Tile tile: game.wall_tiles) {
        ostream << tile << ",";
    }
    ostream << std::endl;

    ostream << "dead wall: ";
    for (const constants::Tile tile: game.dead_tiles) {
        ostream << tile << ",";
    }
    ostream << std::endl;

    ostream << "turn wind: " << game.turn_wind << std::endl;

    ostream << "players:" << std::endl;
    for (const players::Player player: game.all_players) {
        ostream << player << std::endl;
    }
    return ostream;
}

}