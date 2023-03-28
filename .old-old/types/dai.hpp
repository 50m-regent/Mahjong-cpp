#ifndef MAHJONG_DAI_HPP
#define MAHJONG_DAI_HPP

#include <unordered_map>
#include <string>

namespace mahjong {
    enum class Dai: unsigned char {
        Null = 0,

        Liangmian,
        Bianzhang,
        Qianzhang,
        Shuangpeng,
        Danqi,
    };

    class DaiUtilities {
    public:
        static inline const std::unordered_map<Dai, std::string> DISPLAY = {
            {Dai::Null, "Null"},

            {Dai::Liangmian,  "Liangmian"},
            {Dai::Bianzhang,  "Bianzhang"},
            {Dai::Qianzhang,  "Qianzhang"},
            {Dai::Shuangpeng, "Shuangpeng"},
            {Dai::Danqi,      "Danqi"},
        };
    };
}

#endif