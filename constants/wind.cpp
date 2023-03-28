#include "constants.h"

namespace mahjong::constants {

std::ostream& operator<<(
    std::ostream& ostream,
    const Wind wind
) {
    ostream << WIND2STRING.at(wind);

    return ostream;
}

}