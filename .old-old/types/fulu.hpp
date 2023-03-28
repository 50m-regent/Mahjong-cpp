#ifndef MAHJONG_FULU_HPP
#define MAHJONG_FULU_HPP

#include <unordered_map>
#include <string>

#include "mahjong/types/zi.hpp"
#include "mahjong/types/pai.hpp"
#include "mahjong/types/paiset.hpp"

namespace mahjong {
    enum class FuluType: unsigned char {
        Null = 0,

        Peng,
        Chi,
        AnGang,
        MingGang,
        JiaGang,
    };

    enum class Jia: unsigned char {
        Null = 0,

        Shang,
        Zi,
        Xia,
        Duimian,
    };

    class Fulu: Zi {
    private:
        FuluType _type;
        Pai _fulu_pai;
        Paiset _pais;
        Jia _from;

    public:
        static inline const std::unordered_map<FuluType, std::string> DISPLAY = {
            {FuluType::Null, "Null"},

            {FuluType::Peng,     "Peng"},
            {FuluType::Chi,      "Chi"},
            {FuluType::AnGang,   "AnGang"},
            {FuluType::MingGang, "MingGang"},
            {FuluType::JiaGang,  "JiaGang"},
        };

        static inline const std::unordered_map<FuluType, ZiType> FULU_TO_ZI = {
            {FuluType::Null, ZiType::Null},
            
            {FuluType::Peng,     ZiType::MingKezi},
            {FuluType::Chi,      ZiType::MingShunzi},
            {FuluType::AnGang,   ZiType::AnGangzi},
            {FuluType::MingGang, ZiType::MingGangzi},
            {FuluType::JiaGang,  ZiType::MingGangzi},
        };

        Fulu(
            const FuluType type,
            const Pai fulu_pai,
            const Paiset pais,
            const Jia from
        ) : Zi(Fulu::FULU_TO_ZI.at(type), pais), _type(type), _fulu_pai(fulu_pai), _pais(pais), _from(from) {}

        inline ZiType get_zi_type() const {
            return this->get_type();
        }
    };
}

#endif