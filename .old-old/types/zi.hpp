#ifndef MAHJONG_ZI_HPP
#define MAHJONG_ZI_HPP

#include <unordered_map>
#include <string>

#include "mahjong/types/paiset.hpp"

namespace mahjong {
    enum class ZiType: unsigned char {
        Null = 0,

        AnKezi,
        AnShunzi,
        AnGangzi,
        Duizi,

        IsMing = 1 << 3,

        MingKezi   = AnKezi | IsMing,
        MingShunzi = AnShunzi | IsMing,
        MingGangzi = AnGangzi | IsMing,
    };

    inline unsigned char operator&(const ZiType type1, const ZiType type2) {
        return static_cast<unsigned char>(type1) & static_cast<unsigned char>(type2);
    }

    class Zi {
    private:
        ZiType _type;
        Paiset _pais;
        
    public:
        static inline const std::unordered_map<ZiType, std::string> DISPLAY = {
            {ZiType::Null, "Null"},

            {ZiType::AnKezi, "AnKezi"},
            {ZiType::AnShunzi, "AnShunzi"},
            {ZiType::AnGangzi, "AnGangzi"},
            {ZiType::Duizi, "Duizi"},

            {ZiType::MingKezi, "MingKezi"},
            {ZiType::MingShunzi, "MingShunzi"},
            {ZiType::MingGangzi, "MingGangzi"},
        };

        Zi(
            const ZiType type,
            const Paiset pais
        ) : _type(type), _pais(pais) {}

        inline ZiType get_type() const {
            return this->_type;
        }

        inline Paiset get_pais() const {
            return this->_pais;
        }
    };
}

#endif