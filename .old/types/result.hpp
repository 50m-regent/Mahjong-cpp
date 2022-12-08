#ifndef MAHJONG_RESULT_HPP
#define MAHJONG_RESULT_HPP

#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

#include "mahjong/types/shoupai.hpp"
#include "mahjong/types/yi.hpp"
#include "mahjong/types/yiti.hpp"
#include "mahjong/types/zi.hpp"
#include "mahjong/types/dai.hpp"

namespace mahjong {
    enum class ResultFlag: unsigned short {
        Null = 0,

        Zimo            = 1 << 0,
        Lizhi           = 1 << 1,
        Yifa            = 1 << 2,
        Qianggang       = 1 << 3,
        Lingshangkaihua = 1 << 4,
        Haidilaoyue     = 1 << 5,
        Hedilaoyu       = 1 << 6,
        DoubleLizhi     = 1 << 7,
        LiuManguan      = 1 << 8,
        Tianhe          = 1 << 9,
        Dehe            = 1 << 10,
        Renhe           = 1 << 11,
    };

    inline ResultFlag operator&(const ResultFlag flag1, const ResultFlag flag2) {
        return static_cast<ResultFlag>(static_cast<unsigned short>(flag1) & static_cast<unsigned short>(flag2));
    }

    inline ResultFlag operator|(const ResultFlag flag1, const ResultFlag flag2) {
        return static_cast<ResultFlag>(static_cast<unsigned short>(flag1) | static_cast<unsigned short>(flag2));
    }

    class ResultFlagUtilities {
    public:
        static inline const std::unordered_map<ResultFlag, std::string> DISPLAY = {
            {ResultFlag::Null, "Null"},

            {ResultFlag::Zimo,            "Zimo"},
            {ResultFlag::Lizhi,           "Lizhi"},
            {ResultFlag::Yifa,            "Yifa"},
            {ResultFlag::Qianggang,       "Qianggang"},
            {ResultFlag::Lingshangkaihua, "Lingshangkaihua"},
            {ResultFlag::Haidilaoyue,     "Haidilaoyue"},
            {ResultFlag::Hedilaoyu,       "Hedilaoyu"},
            {ResultFlag::DoubleLizhi,     "DoubleLizhi"},
            {ResultFlag::LiuManguan,      "LiuManguan"},
            {ResultFlag::Tianhe,          "Tianhe"},
            {ResultFlag::Dehe,            "Dehe"},
            {ResultFlag::Renhe,           "Renhe"},
        };
    };

    class Result {
    private:
        const Pai _hepai;
        const ResultFlag _flag;
        const Yi _yi;
        const unsigned _han;
        const unsigned _fu;
        const Yiti _yiti;
        const std::vector<unsigned> _score;
        const std::vector<Zi> _zis;

    public:
        Result(
            const Pai hepai,
            const ResultFlag flag,
            const Yi yi,
            const unsigned han, const unsigned fu,
            const Yiti yiti,
            const std::vector<unsigned> score,
            const std::vector<Zi> zis
        ) :
            _hepai(hepai),
            _flag(flag),
            _yi(yi),
            _han(han),
            _fu(fu),
            _yiti(yiti),
            _score(score),
            _zis(zis) {}

        inline Pai get_hepai() const {
            return this->_hepai;
        }

        inline bool is_zimo() const {
            return static_cast<bool>(ResultFlag::Zimo & this->_flag);
        }

        inline Yi get_yi() const {
            return this->_yi;
        }

        inline unsigned get_han() const {
            return this->_han;
        }

        inline unsigned get_fu() const {
            return this->_fu;
        }

        inline Yiti get_yiti() const {
            return this->_yiti;
        }

        inline std::vector<Zi> get_zis() const {
            return this->_zis;
        }
    };

    inline std::ostream &operator<<(std::ostream &os, const Result result) {
        os << "{shoupai:[";
        for (const Zi zi: result.get_zis()) {
            os << zi.get_pais();
        }
        os << "],hepai:" << result.get_hepai();
        os << ",he:" << (result.is_zimo() ? "Zimo" : "Rong");
        os << ",yi:" << result.get_yi();
        os << ",hanfuti:[" << result.get_han() << "," << result.get_fu() << "," << YitiUtilities::DISPLAY.at(result.get_yiti()) << "]";

        return os << "}";
    }
}

#endif