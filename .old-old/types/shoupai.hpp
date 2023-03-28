#ifndef MAHJONG_SHOUPAI_HPP
#define MAHJONG_SHOUPAI_HPP

#include <vector>

#include "mahjong/types/pai.hpp"
#include "mahjong/types/paiset.hpp"
#include "mahjong/types/fulu.hpp"

namespace mahjong {
    class Shoupai {
    private:
        Paiset _pais;
        std::vector<Fulu> _fulus;

    public:
        Shoupai(const Paiset pais) : _pais(pais), _fulus() {};
        Shoupai(
            const Paiset pais,
            const std::vector<Fulu> fulus
        ) : _pais(pais), _fulus(fulus) {};

        inline Paiset get_pais() const;

        bool is_menqianqing() const;
        bool is_fulule() const;
    };
}

#endif