#ifndef MAHJONG_PAI_HPP
#define MAHJONG_PAI_HPP

#include <unordered_map>
#include <string>
#include <iostream>

namespace mahjong {
    enum class Pai: unsigned long long {
        Null = 0,

        YiWan    = 1ull << 0,
        LiangWan = 1ull << 1,
        SanWan   = 1ull << 2,
        SiWan    = 1ull << 3,
        WuWan    = 1ull << 4,
        ChiWuWan = 1ull << 5,
        JinWuWan = 1ull << 6,
        LiuWan   = 1ull << 7,
        QiWan    = 1ull << 8,
        BaWan    = 1ull << 9,
        JiuWan   = 1ull << 10,

        YiTong    = 1ull << 11,
        LiangTong = 1ull << 12,
        SanTong   = 1ull << 13,
        SiTong    = 1ull << 14,
        WuTong    = 1ull << 15,
        ChiWuTong = 1ull << 16,
        JinWuTong = 1ull << 17,
        LiuTong   = 1ull << 18,
        QiTong    = 1ull << 19,
        BaTong    = 1ull << 20,
        JiuTong   = 1ull << 21,

        YiSuo    = 1ull << 22,
        LiangSuo = 1ull << 23,
        SanSuo   = 1ull << 24,
        SiSuo    = 1ull << 25,
        WuSuo    = 1ull << 26,
        ChiWuSuo = 1ull << 27,
        JinWuSuo = 1ull << 28,
        LiuSuo   = 1ull << 29,
        QiSuo    = 1ull << 30,
        BaSuo    = 1ull << 31,
        JiuSuo   = 1ull << 32,

        Dong = 1ull << 33,
        Nan  = 1ull << 34,
        Xi   = 1ull << 35,
        Bei  = 1ull << 36,

        Bai   = 1ull << 37,
        Fa    = 1ull << 38,
        Zhong = 1ull << 39,

        ChunHua = 1ull << 40,
        XiaHua  = 1ull << 41,
        QiuHua  = 1ull << 42,
        DongHua = 1ull << 43,
        MeiHua  = 1ull << 44,
        LanHua  = 1ull << 45,
        JuHua   = 1ull << 46,
        ZhuHua  = 1ull << 47,

        FIRST = YiWan,
        LAST  = ZhuHua,
    };

    inline Pai operator~(const Pai pai) {
        return static_cast<Pai>(~static_cast<unsigned long long>(pai));
    }

    template <typename T>
    inline unsigned long long operator&(const T other, const Pai pai) {
        return other & static_cast<unsigned long long>(pai);
    }

    template <typename T>
    inline unsigned long long operator&=(T &other, const Pai pai) {
        return other &= static_cast<unsigned long long>(pai);
    }

    inline Pai operator|(const Pai pai1, const Pai pai2) {
        return static_cast<Pai>(static_cast<unsigned long long>(pai1) | static_cast<unsigned long long>(pai2));
    }

    template <typename T>
    inline T operator|=(T &other, const Pai pai) {
        return other |= static_cast<unsigned long long>(pai);
    }

    inline unsigned long long operator>>(const Pai pai, const unsigned char other) {
        return static_cast<unsigned long long>(pai) >> other;
    }

    template <typename T>
    inline Pai operator<<=(Pai &pai, const T other) {
        return pai = static_cast<Pai>(static_cast<unsigned long long>(pai) << other);
    }

    class PaiUtilities {
    public:
        static inline const std::unordered_map<Pai, std::string> DISPLAY = {
            {Pai::Null, "Null"},

            {Pai::YiWan,    "1m"},
            {Pai::LiangWan, "2m"},
            {Pai::SanWan,   "3m"},
            {Pai::SiWan,    "4m"},
            {Pai::WuWan,    "5m"},
            {Pai::ChiWuWan, "rm"},
            {Pai::JinWuWan, "gm"},
            {Pai::LiuWan,   "6m"},
            {Pai::QiWan,    "7m"},
            {Pai::BaWan,    "8m"},
            {Pai::JiuWan,   "9m"},

            {Pai::YiTong,    "1p"},
            {Pai::LiangTong, "2p"},
            {Pai::SanTong,   "3p"},
            {Pai::SiTong,    "4p"},
            {Pai::WuTong,    "5p"},
            {Pai::ChiWuTong, "rp"},
            {Pai::JinWuTong, "gp"},
            {Pai::LiuTong,   "6p"},
            {Pai::QiTong,    "7p"},
            {Pai::BaTong,    "8p"},
            {Pai::JiuTong,   "9p"},

            {Pai::YiSuo,    "1s"},
            {Pai::LiangSuo, "2s"},
            {Pai::SanSuo,   "3s"},
            {Pai::SiSuo,    "4s"},
            {Pai::WuSuo,    "5s"},
            {Pai::ChiWuSuo, "rs"},
            {Pai::JinWuSuo, "gs"},
            {Pai::LiuSuo,   "6s"},
            {Pai::QiSuo,    "7s"},
            {Pai::BaSuo,    "8s"},
            {Pai::JiuSuo,   "9s"},

            {Pai::Dong, "Ew"},
            {Pai::Nan,  "Sw"},
            {Pai::Xi,   "Ww"},
            {Pai::Bei,  "Nw"},

            {Pai::Bai,   "B3"},
            {Pai::Fa,    "F3"},
            {Pai::Zhong, "Z3"},

            {Pai::ChunHua, "Cf"},
            {Pai::XiaHua,  "Xf"},
            {Pai::QiuHua,  "Qf"},
            {Pai::DongHua, "Df"},
            {Pai::MeiHua,  "Mf"},
            {Pai::LanHua,  "Lf"},
            {Pai::JuHua,   "Jf"},
            {Pai::ZhuHua,  "Zf"},
        };

        static inline const std::unordered_map<Pai, Pai> DRA = {
            {Pai::YiWan,    Pai::LiangWan},
            {Pai::LiangWan, Pai::SanWan},
            {Pai::SanWan,   Pai::SiWan},
            {Pai::SiWan,    Pai::WuWan | Pai::ChiWuWan | Pai::JinWuWan},
            {Pai::WuWan,    Pai::LiuWan},
            {Pai::ChiWuWan, Pai::LiuWan},
            {Pai::JinWuWan, Pai::LiuWan},
            {Pai::LiuWan,   Pai::QiWan},
            {Pai::QiWan,    Pai::BaWan},
            {Pai::BaWan,    Pai::JiuWan},
            {Pai::JiuWan,   Pai::YiWan},

            {Pai::YiTong,    Pai::LiangTong},
            {Pai::LiangTong, Pai::SanTong},
            {Pai::SanTong,   Pai::SiTong},
            {Pai::SiTong,    Pai::WuTong | Pai::ChiWuTong | Pai::JinWuTong},
            {Pai::WuTong,    Pai::LiuTong},
            {Pai::ChiWuTong, Pai::LiuTong},
            {Pai::JinWuTong, Pai::LiuTong},
            {Pai::LiuTong,   Pai::QiTong},
            {Pai::QiTong,    Pai::BaTong},
            {Pai::BaTong,    Pai::JiuTong},
            {Pai::JiuTong,   Pai::YiTong},

            {Pai::YiSuo,    Pai::LiangSuo},
            {Pai::LiangSuo, Pai::SanSuo},
            {Pai::SanSuo,   Pai::SiSuo},
            {Pai::SiSuo,    Pai::WuSuo | Pai::ChiWuSuo | Pai::JinWuSuo},
            {Pai::WuSuo,    Pai::LiuSuo},
            {Pai::ChiWuSuo, Pai::LiuSuo},
            {Pai::JinWuSuo, Pai::LiuSuo},
            {Pai::LiuSuo,   Pai::QiSuo},
            {Pai::QiSuo,    Pai::BaSuo},
            {Pai::BaSuo,    Pai::JiuSuo},
            {Pai::JiuSuo,   Pai::YiSuo},

            {Pai::Dong, Pai::Nan},
            {Pai::Nan,  Pai::Xi},
            {Pai::Xi,   Pai::Bei},
            {Pai::Bei,  Pai::Dong},

            {Pai::Bai,   Pai::Fa},
            {Pai::Fa,    Pai::Zhong},
            {Pai::Zhong, Pai::Bai},

            {Pai::ChunHua, Pai::XiaHua},
            {Pai::XiaHua,  Pai::QiuHua},
            {Pai::QiuHua,  Pai::DongHua},
            {Pai::DongHua, Pai::MeiHua},
            {Pai::MeiHua,  Pai::LanHua},
            {Pai::LanHua,  Pai::JuHua},
            {Pai::JuHua,   Pai::ZhuHua},
            {Pai::ZhuHua,  Pai::ChunHua},
        };

        template<typename T>
        static inline unsigned count_bit(T n) {
            unsigned long long count = static_cast<unsigned long long>(n);
            count = (count & 0x5555'5555'5555'5555ull) + ((count >>  1) & 0x5555'5555'5555'5555ull);
            count = (count & 0x3333'3333'3333'3333ull) + ((count >>  2) & 0x3333'3333'3333'3333ull);
            count = (count & 0x0f0f'0f0f'0f0f'0f0full) + ((count >>  4) & 0x0f0f'0f0f'0f0f'0f0full);
            count = (count & 0x00ff'00ff'00ff'00ffull) + ((count >>  8) & 0x00ff'00ff'00ff'00ffull);
            count = (count & 0x0000'ffff'0000'ffffull) + ((count >> 16) & 0x0000'ffff'0000'ffffull);
            count = (count & 0x0000'0000'ffff'ffffull) + ((count >> 32) & 0x0000'0000'ffff'ffffull);
            return static_cast<unsigned>(count);
        }
    };

    inline std::ostream &operator<<(std::ostream &os, const Pai pai) {
        return os << PaiUtilities::DISPLAY.at(pai);
    }
}

#endif