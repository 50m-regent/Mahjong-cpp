#include "players.h"

namespace mahjong::players {

std::ostream& operator<<(
    std::ostream& ostream,
    const Player player
) {
    ostream << player.id << ", ";
    ostream << "Wind: " << player.wind << ", ";
    ostream <<

    return ostream;
}

}