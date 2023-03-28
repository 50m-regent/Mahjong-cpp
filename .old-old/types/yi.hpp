#ifndef MAHJONG_YI_HPP
#define MAHJONG_YI_HPP

#include <unordered_map>
#include <string>

namespace mahjong {
    enum class Yi: unsigned long long {
        Null = 0,

        Lizhi             = 1ull << 0,
        Yifa              = 1ull << 1,
        Menqianqingzimohe = 1ull << 2,
        Sanyuanpai        = 1ull << 3,
        Changfeng         = 1ull << 4,
        Zifeng            = 1ull << 5,
        Duanyao           = 1ull << 6,
        Pinghe            = 1ull << 7,
        Yibeikou          = 1ull << 8,
        Haidilaoyue       = 1ull << 9,
        Hedilaoyu         = 1ull << 10,
        Lingshangkaihua   = 1ull << 11,
        Qianggang         = 1ull << 12,

        DoubleLizhi      = 1ull << 13,
        Sansetongshun    = 1ull << 14,
        Sansetongke      = 1ull << 15,
        Sananke          = 1ull << 16,
        Yiqitongguan     = 1ull << 17,
        Qiduizi          = 1ull << 18,
        Duiduihe         = 1ull << 19,
        Hunquandaiyaojiu = 1ull << 20,
        Sangangzi        = 1ull << 21,
        Xiaosanyuan      = 1ull << 22,
        Hunlaotou        = 1ull << 23,

        Liangbeikou       = 1ull << 24,
        Chunquandaiyaojiu = 1ull << 25,
        Hunyise           = 1ull << 26,

        Qianyise = 1ull << 27,

        Sianke         = 1ull << 28,
        Daisanyuan     = 1ull << 29,
        Guoshiwushuang = 1ull << 30,
        Luyise         = 1ull << 31,
        Ziyise         = 1ull << 32,
        Qianlaotou     = 1ull << 33,
        Sigangzi       = 1ull << 34,
        Xiaosixi       = 1ull << 35,
        Jiulianbaodeng = 1ull << 36,
        Dehe           = 1ull << 37,
        Tianhe         = 1ull << 38,

        Daisixi                     = 1ull << 39,
        SiankeDanqi                 = 1ull << 40,
        GuoshiwushuangShisanmiandai = 1ull << 41,
        ChunzhengJiulianbaodeng     = 1ull << 42,
        ChunzhengLuyise             = 1ull << 43,

        LiuManguan = 1ull << 44,

        FIRST = Lizhi,
        LAST  = LiuManguan,
    };

    inline unsigned long long operator&(const Yi yi1, const Yi yi2) {
        return static_cast<unsigned long long>(yi1) & static_cast<unsigned long long>(yi2);
    }

    inline Yi operator|(const Yi yi1, const Yi yi2) {
        return static_cast<Yi>(static_cast<unsigned long long>(yi1) | static_cast<unsigned long long>(yi2));
    }

    template <typename T>
    inline Yi operator<<=(Yi &yi, const T other) {
        return yi = static_cast<Yi>(static_cast<unsigned long long>(yi) << other);
    }

    class YiUtilities {
    public:
        static inline const std::unordered_map<Yi, std::pair<unsigned char, unsigned char>> INFO = {
            {Yi::Null, {0, 0}},

            {Yi::Lizhi,             {1, 0}},
            {Yi::Yifa,              {1, 0}},
            {Yi::Menqianqingzimohe, {1, 0}},
            {Yi::Sanyuanpai,        {1, 1}},
            {Yi::Changfeng,         {1, 1}},
            {Yi::Zifeng,            {1, 1}},
            {Yi::Duanyao,           {1, 1}},
            {Yi::Pinghe,            {1, 0}},
            {Yi::Yibeikou,          {1, 0}},
            {Yi::Haidilaoyue,       {1, 1}},
            {Yi::Hedilaoyu,         {1, 1}},
            {Yi::Lingshangkaihua,   {1, 1}},
            {Yi::Qianggang,         {1, 1}},

            {Yi::DoubleLizhi,      {2, 0}},
            {Yi::Sansetongshun,    {2, 1}},
            {Yi::Sansetongke,      {2, 2}},
            {Yi::Sananke,          {2, 2}},
            {Yi::Yiqitongguan,     {2, 1}},
            {Yi::Qiduizi,          {2, 0}},
            {Yi::Duiduihe,         {2, 2}},
            {Yi::Hunquandaiyaojiu, {2, 1}},
            {Yi::Sangangzi,        {2, 2}},
            {Yi::Xiaosanyuan,      {2, 2}},
            {Yi::Hunlaotou,        {2, 2}},

            {Yi::Liangbeikou,       {3, 0}},
            {Yi::Chunquandaiyaojiu, {3, 2}},
            {Yi::Hunyise,           {3, 2}},

            {Yi::Qianyise, {6, 5}},

            {Yi::Sianke,         {13, 0}},
            {Yi::Daisanyuan,     {13, 13}},
            {Yi::Guoshiwushuang, {13, 0}},
            {Yi::Luyise,         {13, 13}},
            {Yi::Ziyise,         {13, 13}},
            {Yi::Qianlaotou,     {13, 13}},
            {Yi::Sigangzi,       {13, 13}},
            {Yi::Xiaosixi,       {13, 13}},
            {Yi::Jiulianbaodeng, {13, 0}},
            {Yi::Dehe,           {13, 0}},
            {Yi::Tianhe,         {13, 0}},

            {Yi::Daisixi,                     {26, 26}},
            {Yi::SiankeDanqi,                 {26, 0}},
            {Yi::GuoshiwushuangShisanmiandai, {26, 0}},
            {Yi::ChunzhengJiulianbaodeng,     {26, 0}},
            {Yi::ChunzhengLuyise,             {26, 26}},

            {Yi::LiuManguan, {5, 5}},
        };

        static inline const std::unordered_map<Yi, std::string> DISPLAY = {
            {Yi::Null, "Null"},

            {Yi::Lizhi,             "Lizhi"},
            {Yi::Yifa,              "Yifa"},
            {Yi::Menqianqingzimohe, "Menqianqingzimohe"},
            {Yi::Sanyuanpai,        "Sanyuanpai"},
            {Yi::Changfeng,         "Changfeng"},
            {Yi::Zifeng,            "Zifeng"},
            {Yi::Duanyao,           "Duanyao"},
            {Yi::Pinghe,            "Pinghe"},
            {Yi::Yibeikou,          "Yibeikou"},
            {Yi::Haidilaoyue,       "Haidilaoyue"},
            {Yi::Hedilaoyu,         "Hedilaoyu"},
            {Yi::Lingshangkaihua,   "Lingshangkaihua"},
            {Yi::Qianggang,         "Qianggang"},

            {Yi::DoubleLizhi,      "DoubleLizhi"},
            {Yi::Sansetongshun,    "Sansetongshun"},
            {Yi::Sansetongke,      "Sansetongke"},
            {Yi::Sananke,          "Sananke"},
            {Yi::Yiqitongguan,     "Yigiyongguan"},
            {Yi::Qiduizi,          "Qiduizi"},
            {Yi::Duiduihe,         "Duiduihe"},
            {Yi::Hunquandaiyaojiu, "Hunquandaiyaojiu"},
            {Yi::Sangangzi,        "Sangangzi"},
            {Yi::Xiaosanyuan,      "Xiaosanyuan"},
            {Yi::Hunlaotou,        "Hunlaotou"},

            {Yi::Liangbeikou,       "Liangbeikou"},
            {Yi::Chunquandaiyaojiu, "Chunquandaiyaojiu"},
            {Yi::Hunyise,           "Hunyise"},

            {Yi::Qianyise, "Qiyise"},

            {Yi::Sianke,         "Sianke"},
            {Yi::Daisanyuan,     "Daisanyuan"},
            {Yi::Guoshiwushuang, "Guoshiwushuang"},
            {Yi::Luyise,         "Luyise"},
            {Yi::Ziyise,         "Ziyise"},
            {Yi::Qianlaotou,     "Qianlaotou"},
            {Yi::Sigangzi,       "Sigangzi"},
            {Yi::Xiaosixi,       "Xiaosixi"},
            {Yi::Jiulianbaodeng, "Jiulianbaodeng"},
            {Yi::Dehe,           "Dehe"},
            {Yi::Tianhe,         "Tianhe"},

            {Yi::Daisixi,                     "Daisixi"},
            {Yi::SiankeDanqi,                 "SiankeDanqi"},
            {Yi::GuoshiwushuangShisanmiandai, "GuoshiwushuangShisanmiandai"},
            {Yi::ChunzhengJiulianbaodeng,     "ChunzhengJiulianbaodeng"},
            {Yi::ChunzhengLuyise,             "ChunzhengLuyise"},

            {Yi::LiuManguan, "LiuManguan"},
        };
    };

    inline std::ostream &operator<<(std::ostream &os, const Yi yis) {
        os << "[";
        for (Yi yi = Yi::FIRST; yi <= Yi::LAST; yi <<= 1) {
            if (yi & yis) {
                os << YiUtilities::DISPLAY.at(yi) << ",";
            }
        }

        return os << "]";
    }
}

#endif