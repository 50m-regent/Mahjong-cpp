#include "mahjong/types/paiset.hpp"
#include "mahjong/types/pai.hpp"

using namespace mahjong;

bool Paiset::add(const Pai pai) {
    assert (1 == PaiUtilities::count_bit(pai));

    if (this->_pais.at(3) & pai) {
        return false;
    } else if (this->_pais.at(2) & pai) {
        this->_pais.at(3) |= pai;
        return true;
    } else if (this->_pais.at(1) & pai) {
        this->_pais.at(2) |= pai;
        return true;
    } else if (this->_pais.at(0) & pai) {
        this->_pais.at(1) |= pai;
        return true;
    } else {
        this->_pais.at(0) |= pai;
        return true;
    }

    return false;
}

bool Paiset::remove(const Pai pai) {
    assert (1 == PaiUtilities::count_bit(pai));

    if (!(this->_pais.at(0) & pai)) {
        return false;
    } else if (!(this->_pais.at(1) & pai)) {
        this->_pais.at(0) &= ~pai;
        return true;
    } else if (!(this->_pais.at(2) & pai)) {
        this->_pais.at(1) &= ~pai;
        return true;
    } else if (!(this->_pais.at(3) & pai)) {
        this->_pais.at(2) &= ~pai;
        return true;
    } else {
        this->_pais.at(3) &= ~pai;
        return true;
    }

    return false;
}

Paiset::Paiset(const std::vector<Pai> pais) : _pais(4, 0) {
    for (const Pai pai: pais) {
        this->add(pai);
    }
}

unsigned Paiset::pai_count() const {
    unsigned count = 0;
    for (const unsigned long long pais: this->_pais) {
        count += PaiUtilities::count_bit(pais);
    }

    return count;
}

unsigned Paiset::count_pai(const Pai pai) const {
    unsigned count = 0;
    for (const unsigned long long pais: this->_pais) {
        count += PaiUtilities::count_bit(pais & pai);
    }

    return count;
}