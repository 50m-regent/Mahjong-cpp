#ifndef MAHJONG_ROUND_H
#define MAHJONG_ROUND_H

#include <vector>
#include <algorithm>
#include <random>
#include <memory>

#include "players/players.h"
#include "constants/constants.h"
#include "tiles.h"

namespace mahjong {

class Round {
public:
    Round(
        const Wind wind,
        const uint8_t round_count,
        const uint8_t lizhi_bar_count,
        const uint8_t carry_bar_count,
        const std::vector<std::shared_ptr<Player>> players,
        const bool has_red
    ) : _wind(wind),
        _round_count(round_count),
        _lizhi_bar_count(lizhi_bar_count),
        _carry_bar_count(carry_bar_count),
        _players(players),
        _has_red(has_red),
        _turn(Wind::NONE) {
        this->_shuffle_tiles(has_red);
    }

    friend inline std::ostream &operator<<(std::ostream &os, const Round round) noexcept {
        os << "{";
        
        os << "wind:'" << WIND_DISPLAY.at(round._wind) << "',";
        os << "round_count:" << static_cast<unsigned int>(round._round_count) << ",";
        os << "turn:'" << WIND_DISPLAY.at(round._turn) << "',";
        os << "players:[";
        bool is_first = true;
        for (const std::shared_ptr<Player> player: round._players) {
            if (is_first) {
                is_first = false;
            } else {
                os << ",";
            }
            os << *player;
        }
        os << "],";
        os << "wall:" << round._wall << ",";
        os << "dead:" << round._dead << ",";
        os << "actions:";

        os << "}";

        return os;
    }

    inline const Wind get_wind() const noexcept {
        return this->_wind;
    }
    
    inline void proceed() noexcept {
        this->_wind = (
            this->_players.size() == this->_round_count &&
            !this->_is_carrying()
        ) ? NEXT_WIND.at(this->_wind) :
            this->_wind;

        this->_round_count = this->_is_carrying() ?
            this->_round_count :
            (this->_round_count % this->_players.size() + 1);

        this->_lizhi_bar_count = this->_is_drawn() ?
            this->_lizhi_bar_count + this->_lizhi_count() :
            0;

        this->_carry_bar_count = this->_is_carrying() ?
            this->_carry_bar_count + 1 :
            0;

        this->_shuffle_tiles(this->_has_red);
    }

    void play(std::ostream &os) noexcept {
        this->_deal();

        os << *this << std::endl;

        this->_turn = Wind::EAST;
        while (!this->_end()) {
            this->_step(os);
        }
    }

private:
    inline void _shuffle_tiles(const bool has_red) noexcept {
        std::vector<Tile> tiles;

        if (has_red) {
            tiles = {
                Tile::C1, Tile::C1, Tile::C1, Tile::C1,
                Tile::C2, Tile::C2, Tile::C2, Tile::C2,
                Tile::C3, Tile::C3, Tile::C3, Tile::C3,
                Tile::C4, Tile::C4, Tile::C4, Tile::C4,
                Tile::C5, Tile::C5, Tile::C5, Tile::CR,
                Tile::C6, Tile::C6, Tile::C6, Tile::C6,
                Tile::C7, Tile::C7, Tile::C7, Tile::C7,
                Tile::C8, Tile::C8, Tile::C8, Tile::C8,
                Tile::C9, Tile::C9, Tile::C9, Tile::C9,

                Tile::D1, Tile::D1, Tile::D1, Tile::D1,
                Tile::D2, Tile::D2, Tile::D2, Tile::D2,
                Tile::D3, Tile::D3, Tile::D3, Tile::D3,
                Tile::D4, Tile::D4, Tile::D4, Tile::D4,
                Tile::D5, Tile::D5, Tile::D5, Tile::DR,
                Tile::D6, Tile::D6, Tile::D6, Tile::D6,
                Tile::D7, Tile::D7, Tile::D7, Tile::D7,
                Tile::D8, Tile::D8, Tile::D8, Tile::D8,
                Tile::D9, Tile::D9, Tile::D9, Tile::D9,

                Tile::B1, Tile::B1, Tile::B1, Tile::B1,
                Tile::B2, Tile::B2, Tile::B2, Tile::B2,
                Tile::B3, Tile::B3, Tile::B3, Tile::B3,
                Tile::B4, Tile::B4, Tile::B4, Tile::B4,
                Tile::B5, Tile::B5, Tile::B5, Tile::BR,
                Tile::B6, Tile::B6, Tile::B6, Tile::B6,
                Tile::B7, Tile::B7, Tile::B7, Tile::B7,
                Tile::B8, Tile::B8, Tile::B8, Tile::B8,
                Tile::B9, Tile::B9, Tile::B9, Tile::B9,

                Tile::EAST,  Tile::EAST,  Tile::EAST,  Tile::EAST,
                Tile::SOUTH, Tile::SOUTH, Tile::SOUTH, Tile::SOUTH,
                Tile::WEST,  Tile::WEST,  Tile::WEST,  Tile::WEST,
                Tile::NORTH, Tile::NORTH, Tile::NORTH, Tile::NORTH,

                Tile::WHITE, Tile::WHITE, Tile::WHITE, Tile::WHITE,
                Tile::GREEN, Tile::GREEN, Tile::GREEN, Tile::GREEN,
                Tile::RED,   Tile::RED,   Tile::RED,   Tile::RED,
            };
        } else {
            tiles = {
                Tile::C1, Tile::C1, Tile::C1, Tile::C1,
                Tile::C2, Tile::C2, Tile::C2, Tile::C2,
                Tile::C3, Tile::C3, Tile::C3, Tile::C3,
                Tile::C4, Tile::C4, Tile::C4, Tile::C4,
                Tile::C5, Tile::C5, Tile::C5, Tile::C5,
                Tile::C6, Tile::C6, Tile::C6, Tile::C6,
                Tile::C7, Tile::C7, Tile::C7, Tile::C7,
                Tile::C8, Tile::C8, Tile::C8, Tile::C8,
                Tile::C9, Tile::C9, Tile::C9, Tile::C9,

                Tile::D1, Tile::D1, Tile::D1, Tile::D1,
                Tile::D2, Tile::D2, Tile::D2, Tile::D2,
                Tile::D3, Tile::D3, Tile::D3, Tile::D3,
                Tile::D4, Tile::D4, Tile::D4, Tile::D4,
                Tile::D5, Tile::D5, Tile::D5, Tile::D5,
                Tile::D6, Tile::D6, Tile::D6, Tile::D6,
                Tile::D7, Tile::D7, Tile::D7, Tile::D7,
                Tile::D8, Tile::D8, Tile::D8, Tile::D8,
                Tile::D9, Tile::D9, Tile::D9, Tile::D9,

                Tile::B1, Tile::B1, Tile::B1, Tile::B1,
                Tile::B2, Tile::B2, Tile::B2, Tile::B2,
                Tile::B3, Tile::B3, Tile::B3, Tile::B3,
                Tile::B4, Tile::B4, Tile::B4, Tile::B4,
                Tile::B5, Tile::B5, Tile::B5, Tile::B5,
                Tile::B6, Tile::B6, Tile::B6, Tile::B6,
                Tile::B7, Tile::B7, Tile::B7, Tile::B7,
                Tile::B8, Tile::B8, Tile::B8, Tile::B8,
                Tile::B9, Tile::B9, Tile::B9, Tile::B9,

                Tile::EAST,  Tile::EAST,  Tile::EAST,  Tile::EAST,
                Tile::SOUTH, Tile::SOUTH, Tile::SOUTH, Tile::SOUTH,
                Tile::WEST,  Tile::WEST,  Tile::WEST,  Tile::WEST,
                Tile::NORTH, Tile::NORTH, Tile::NORTH, Tile::NORTH,

                Tile::WHITE, Tile::WHITE, Tile::WHITE, Tile::WHITE,
                Tile::GREEN, Tile::GREEN, Tile::GREEN, Tile::GREEN,
                Tile::RED,   Tile::RED,   Tile::RED,   Tile::RED,
            };
        }

        std::random_device seed_generator;
        std::mt19937_64 engine(seed_generator());
        std::shuffle(tiles.begin(), tiles.end(), engine);

        const uint8_t dead_size = (3 == this->_players.size()) ? 18 : 14;
        this->_dead = Tiles(std::vector<Tile>(tiles.begin(), tiles.begin() + dead_size));
        this->_wall = Tiles(std::vector<Tile>(tiles.begin() + dead_size, tiles.end()));
    }

    inline const bool _is_carrying() const noexcept {
        return false;
    }

    inline const bool _is_drawn() const noexcept {
        return false;
    }

    inline const uint8_t _lizhi_count() const noexcept {
        return 0;
    }

    inline void _pick(std::shared_ptr<Player> player) noexcept {
        const Tile picked_tile = this->_wall.pop();
        assert (Tile::NONE != picked_tile);
        player->pick(picked_tile);
    }

    void _deal() noexcept {
        for (const std::shared_ptr<Player> player: this->_players) {
            player->clear();
            for (uint8_t i = 0; i < 13; ++i) {
                this->_pick(player);
            }       
        }
    }

    inline const bool _end() const noexcept {
        return !Tiles::count(this->_wall);
    }

    void _step(std::ostream& os) noexcept {
        this->_pick(this->_players[this->_turn - 1]);
        os << *this << std::endl;

        this->_players[this->_turn - 1]->discard();
        assert (13 == Tiles::count(this->_players[this->_turn - 1]->get_tiles()));
        
        // os << *this << std::endl;

        this->_turn = NEXT_WIND.at(this->_turn);
    }

    Wind _wind;
    uint8_t _round_count;
    uint8_t _lizhi_bar_count;
    uint8_t _carry_bar_count;
    std::vector<std::shared_ptr<Player>> _players;
    const bool _has_red;

    Tiles _wall;
    Tiles _dead;
    Wind _turn;
};

}

#endif