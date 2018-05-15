#ifndef UUID_H
#define UUID_H

// C Standard Library
#include <cctype>
#include <cstdint>
// C++ Standard Library
#include <array>
#include <string>

class UUID
{
public:
    // 8-4-4-4-12 representation of UUID
    struct UUID_
    {
        union
        {
            struct {
                uint32_t time_low;
                uint16_t time_mid;
                uint16_t time_hi_and_version;
                uint8_t clock_seq_hi_and_res;
                uint8_t clock_seq_low;
                uint8_t node[6];
            } uuid;
            struct {
                uint32_t time_low;
                uint16_t time_mid;
                uint16_t time_hi_and_version;
                uint16_t clock_seq;
                uint16_t node[3];
            };
        };
    };

    enum class Format
    {
        Canonical = 0b0000'0001,
        Microsoft = 0b0000'0010,
        LowerCase = 0b0000'0100,
        UpperCase = 0b0000'1000,
    };

    static constexpr size_t UUID_Size = sizeof (UUID_);

public:
    UUID(std::string const& uuid);
    UUID(std::wstring const& uuid);
    UUID(std::array<uint8_t, UUID_Size> const& uuid);

public:
    auto AsArray() const -> std::array<uint8_t, UUID_Size>;
    auto AsCanonicalString() const -> std::string const&;
    auto AsCanonicalWString() -> std::wstring;
    auto AsString() const -> std::string;
    auto AsWString() const -> std::wstring;

public:
    auto ClearFormat() -> void;
    auto Empty() const -> bool;
    auto Format(int formatFlags) -> void;

private:
    template <typename StringType>
    auto ApplyCharacterFormat(StringType const& str) const -> StringType;

private:
    int formatFlags {0};
    bool isEmpty {true};
    std::array<uint8_t, UUID_Size> uuid;
    std::string uuidCanonicalString;
};

template <typename StringType>
inline auto UUID::ApplyCharacterFormat(StringType const& str) const
-> StringType
{
    if (this->formatFlags & static_cast<int>(Format::UpperCase))
    {
        return ConvertToUpperCase(str);
    }
    else
    {
        return ConvertToLowerCase(str);
    }
}

inline
std::string ConvertToLowerCase(std::string str)
{
    // std::tolower requires the char argument to be converted to unsigned
    // int to avoid undefined behavior
    std::transform (str.begin (), str.end (), str.begin(),
        [](uint8_t c) {return std::tolower (c);
    });

    return  str;
}

inline
std::wstring ConvertToLowerCase(std::wstring str)
{
    // std::tolower requires the char argument to be converted to unsigned
    // int to avoid undefined behavior
    std::transform (str.begin (), str.end (), str.begin(),
        [](wchar_t c) {return static_cast<wchar_t>(std::tolower (c));
    });

    return  str;
}

inline
std::string ConvertToUpperCase(std::string str)
{
    // std::tolower requires the char argument to be converted to unsigned
    // int to avoid undefined behavior
    std::transform (str.begin (), str.end (), str.begin(),
        [](uint8_t c) {return std::toupper (c);
    });

    return  str;
}

inline
std::wstring ConvertToUpperCase(std::wstring str)
{
    // std::tolower requires the char argument to be converted to unsigned
    // int to avoid undefined behavior
    std::transform (str.begin (), str.end (), str.begin(),
        [](wchar_t c) {return static_cast<wchar_t>(std::toupper (c));
    });

    return  str;
}

#endif // UUID_H
