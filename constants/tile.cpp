#include "constants.h"

namespace mahjong::constants {

std::ostream& operator<<(
    std::ostream& ostream,
    const Tile tile
) {
    ostream << TILE2STRING.at(tile);

    return ostream;
}

}