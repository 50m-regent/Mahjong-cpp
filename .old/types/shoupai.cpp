#include "mahjong/types/shoupai.hpp"
#include "mahjong/types/paiset.hpp"
#include "mahjong/types/fulu.hpp"
#include "mahjong/types/zi.hpp"

using namespace mahjong;

inline Paiset Shoupai::get_pais() const {
    return this->_pais;
}

bool Shoupai::is_menqianqing() const {
    for (const Fulu fulu: this->_fulus) {
        if ((ZiType::IsMing & fulu.get_zi_type())) {
            return false;
        }
    }
    return true;
}

bool Shoupai::is_fulule() const {
    return !this->_fulus.empty();
}