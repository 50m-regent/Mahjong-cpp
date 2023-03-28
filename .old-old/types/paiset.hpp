#ifndef MAHJONG_PAISET_HPP
#define MAHJONG_PAISET_HPP

#include <vector>
#include <iostream>

#include "mahjong/types/pai.hpp"

namespace mahjong {
    class Paiset {
    private:
        std::vector<unsigned long long> _pais;

    public:
        Paiset(const std::vector<Pai> pais);

        bool add(const Pai pai);
        bool remove(const Pai pai);

        unsigned pai_count() const;
        unsigned count_pai(const Pai pai) const;
    };

    inline std::ostream &operator<<(std::ostream &os, const Paiset pais) {
        os << "[";
        for (Pai pai = Pai::FIRST; pai <= Pai::LAST; pai <<= 1) {
            unsigned char n = pais.count_pai(pai);
            while (n--) {
                os << pai << ",";
            }
        }

        return os << "]";
    }
}

#endif