#pragma once

namespace mahjong::players {

class Player {
public:
    friend std::ostream& operator<<(
        std::ostream&,
        const Player
    );
};

}