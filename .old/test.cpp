#include <iostream>
#include <vector>

#include "mahjong.hpp"

using namespace mahjong;

int main() {
    const Paiset paiset(std::vector<Pai>{
        Pai::YiWan,
        Pai::YiWan,
        Pai::YiWan,
    });

    const Result result(
        Pai::YiWan,
        ResultFlag::Zimo,
        Yi::ChunzhengJiulianbaodeng,
        26, 0,
        Yiti::DoubleYiman,
        {96000, 0, 0},
        {
            Zi(ZiType::AnKezi,   Paiset({Pai::YiWan, Pai::YiWan, Pai::YiWan})),
            Zi(ZiType::AnShunzi, Paiset({Pai::YiWan, Pai::LiangWan, Pai::SanWan})),
            Zi(ZiType::AnShunzi, Paiset({Pai::SiWan, Pai::ChiWuWan, Pai::LiuWan})),
            Zi(ZiType::AnShunzi, Paiset({Pai::QiWan, Pai::BaWan, Pai::JiuWan})),
            Zi(ZiType::Duizi,    Paiset({Pai::JiuWan, Pai::JiuWan})),
        }
    );

    std::cout<<result<<std::endl;

    return 0;
}