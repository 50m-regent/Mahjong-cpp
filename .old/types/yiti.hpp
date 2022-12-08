#ifndef MAHJONG_YITI_HPP
#define MAHJONG_YITI_HPP

#include <unordered_map>
#include <string>

namespace mahjong {
    enum class Yiti: unsigned char {
        Null = 0,

        Manguan,
        Tiaoman,
        Beiman,
        Sanbeiman,

        Yiman,
        DoubleYiman,
        TripleYiman,
        QuadrupleYiman,
        QuintupleYiman,
        SextupleYiman,
        SeptupleYiman,
        OctupleYiman,
        NonupleYiman,
    };

    class YitiUtilities {
    private:
        static inline constexpr bool _is_manguan(
            const unsigned char han,
            const unsigned char fu
        ) {
            assert (3 == han || 4 == han);

            return (3 == han && fu >= 70) || (4 == han && fu >= 40);
        }

    public:
        static inline const std::unordered_map<Yiti, std::string> DISPLAY = {
            {Yiti::Null, "Null"},

            {Yiti::Manguan,   "Manguan"},
            {Yiti::Tiaoman,   "Tiaoman"},
            {Yiti::Beiman,    "Beiman"},
            {Yiti::Sanbeiman, "Sanbeiman"},

            {Yiti::Yiman,          "Yiman"},
            {Yiti::DoubleYiman,    "DoubleYiman"},
            {Yiti::TripleYiman,    "TripleYiman"},
            {Yiti::QuadrupleYiman, "QuadrupleYiman"},
            {Yiti::QuintupleYiman, "QuintupleYiman"},
            {Yiti::SextupleYiman,  "SextupleYiman"},
            {Yiti::SeptupleYiman,  "SeptupleYiman"},
            {Yiti::OctupleYiman,   "OctupleYiman"},
            {Yiti::NonupleYiman,   "NonupleYiman"},
        };

        static inline constexpr Yiti get_yiti(
            const unsigned char han,
            const unsigned char fu
        ) {
            const unsigned char yiman_count = han / 13;
            switch (yiman_count) {
            case 0:
                if (han < 3) {
                    return Yiti::Null;
                } else if (han < 5) {
                    return YitiUtilities::_is_manguan(han, fu) ? Yiti::Manguan : Yiti::Null;
                } else if (han < 6) {
                    return Yiti::Manguan;
                } else if (han < 8) {
                    return Yiti::Tiaoman;
                } else if (han < 11) {
                    return Yiti::Beiman;
                } else if (han < 13) {
                    return Yiti::Sanbeiman;
                }
            case 1:
                return Yiti::Yiman;
            case 2:
                return Yiti::DoubleYiman;
            case 3:
                return Yiti::TripleYiman;
            case 4:
                return Yiti::QuadrupleYiman;
            case 5:
                return Yiti::QuintupleYiman;
            case 6:
                return Yiti::SextupleYiman;
            case 7:
                return Yiti::SeptupleYiman;
            case 8:
                return Yiti::OctupleYiman;
            case 9:
                return Yiti::NonupleYiman;
            }

            return Yiti::Null;
        }
    };
}

#endif