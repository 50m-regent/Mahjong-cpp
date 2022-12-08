#ifndef MAHJONG_SCORE_HPP
#define MAHJONG_SCORE_HPP

#include <cmath>
#include <vector>
#include <unordered_map>

#include "mahjong/types/yiti.hpp"

namespace mahjong {
    class Score {
    private:
        static inline constexpr unsigned _round_up_score(const unsigned score) {
            return static_cast<int>(std::ceil(static_cast<double>(score) / 100.0)) * 100;
        }
    public:
        static inline constexpr unsigned round_up_fu(const unsigned char fu) {
            return static_cast<int>(std::ceil(static_cast<double>(fu) / 10.0)) * 10;
        }

        static inline constexpr unsigned to_parent_rong(
            const unsigned char han,
            const unsigned char fu,
            const Yiti yiti=Yiti::Null
        ) {
            assert ((25 == fu) || !(fu % 10));

            switch (yiti) {
            case Yiti::Null:
                return Score::_round_up_score(fu * 6 * std::pow(2, han + 2));

            case Yiti::Manguan:
                return 12000;
            case Yiti::Tiaoman:
                return 18000;
            case Yiti::Beiman:
                return 24000;
            case Yiti::Sanbeiman:
                return 36000;

            case Yiti::Yiman:
                return 48000;
            case Yiti::DoubleYiman:
                return 96000;
            case Yiti::TripleYiman:
                return 144000;
            case Yiti::QuadrupleYiman:
                return 192000;
            case Yiti::QuintupleYiman:
                return 240000;
            case Yiti::SextupleYiman:
                return 288000;
            case Yiti::SeptupleYiman:
                return 336000;
            case Yiti::OctupleYiman:
                return 384000;
            case Yiti::NonupleYiman:
                return 432000;
            }

            return 0;
        }

        static inline constexpr unsigned to_child_rong(
            const unsigned char han,
            const unsigned char fu,
            const Yiti yiti=Yiti::Null
        ) {
            assert ((25 == fu) || !(fu % 10));

            switch (yiti) {
            case Yiti::Null:
                return Score::_round_up_score(fu * 4 * std::pow(2, han + 2));

            case Yiti::Manguan:
                return 8000;
            case Yiti::Tiaoman:
                return 12000;
            case Yiti::Beiman:
                return 16000;
            case Yiti::Sanbeiman:
                return 24000;

            case Yiti::Yiman:
                return 32000;
            case Yiti::DoubleYiman:
                return 64000;
            case Yiti::TripleYiman:
                return 96000;
            case Yiti::QuadrupleYiman:
                return 128000;
            case Yiti::QuintupleYiman:
                return 160000;
            case Yiti::SextupleYiman:
                return 192000;
            case Yiti::SeptupleYiman:
                return 224000;
            case Yiti::OctupleYiman:
                return 256000;
            case Yiti::NonupleYiman:
                return 288000;
            }

            return 0;
        }

        static inline constexpr unsigned to_parent_zimo(
            const unsigned char han,
            const unsigned char fu,
            const Yiti yiti=Yiti::Null
        ) {
            assert ((25 == fu) || !(fu % 10));

            return Score::_round_up_score(Score::to_parent_rong(han, fu, yiti) / 3);
        }

        static inline constexpr unsigned parent_to_child_zimo(
            const unsigned char han,
            const unsigned char fu,
            const Yiti yiti=Yiti::Null
        ) {
            assert ((25 == fu) || !(fu % 10));

            return Score::_round_up_score(Score::to_child_rong(han, fu, yiti) / 2);
        }

        static inline constexpr unsigned child_to_child_zimo(
            const unsigned char han,
            const unsigned char fu,
            const Yiti yiti=Yiti::Null
        ) {
            assert ((25 == fu) || !(fu % 10));

            return Score::_round_up_score(Score::to_child_rong(han, fu, yiti) / 4);
        }
    };
}

#endif