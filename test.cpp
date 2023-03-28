#include <future>
#include <unistd.h>
#include <iostream>

#include "mahjong.h"

int main() {
    const mahjong::Mahjong game = mahjong::Mahjong(
        mahjong::constants::Wind::EAST,
        std::vector<mahjong::players::Player>{
            mahjong::players::RandomPlayer(),
            mahjong::players::RandomPlayer(),
            mahjong::players::RandomPlayer(),
            mahjong::players::RandomPlayer(),
        },
        25000
    );
    
    std::thread game_thread = std::thread([&game] {
        game.play();
    });

    while (!game.is_end()) {
        sleep(100);
        std::cout << game << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }

    game_thread.join();
}