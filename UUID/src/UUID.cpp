// Self
#include "UUID.hpp"
// C Standard Library
#include <cctype>
#include <cstdlib>
#include <cwchar>
// C++ Standard Library
#include <iomanip>
#include <regex>
#include <sstream>
#include <string>

#include <iostream>

UUID::UUID(std::string const& uuid)
    : uuid { {0} }
    , uuidCanonicalString{uuid}
{
    // 8-4-4-4-12 representation of UUID
    std::regex pattern {"(.+)\\-(.+)\\-(.+)\\-(.+)\\-(.+)"};

    std::smatch matches;
    this->isEmpty =
            !(std::regex_match(this->uuidCanonicalString, matches, pattern));

    // Initialize stuct of union of structs with a array member
    UUID_ uuid_{{{0, 0, 0, 0, 0, {0}}}};

    // The first sub_match (index 0) contained in a match_result always
    // represents the full match within a target sequence made by a regex, and
    // subsequent sub_matches represent sub-expression matches corresponding in
    // sequence to the left parenthesis delimiting the sub-expression in the
    // regex.
    std::istringstream(matches[1].str())
            >> std::hex >> uuid_.time_low;
    std::istringstream(matches[2].str())
            >> std::hex >> uuid_.time_mid;
    std::istringstream(matches[3].str())
            >> std::hex >> uuid_.time_hi_and_version;
    // Split the bytes
    std::istringstream(matches[4].str())
            >> std::hex >> uuid_.clock_seq;
    constexpr auto nodeArraySize = sizeof(uuid_.node) / sizeof(*uuid_.node);
    for (size_t i = 0; i < nodeArraySize; ++i)
    {
        auto const& substr = matches[5].str().substr(i * 4, 4);
        std::istringstream(substr)
                >> std::hex >> uuid_.node[i];
    }

    std::memcpy(this->uuid.data(), &uuid_, UUID_Size);
    this->isEmpty = false;
}

UUID::UUID(std::array<uint8_t, UUID_Size> const& uuid)
    : uuid{uuid}
{
    UUID_ uuid_{};
    std::memcpy(&uuid_, this->uuid.data(), UUID_Size);
    std::stringstream ss;
    // Interpret the values as hexadecimal
    ss << std::hex;
    // Set the width of the stream and the character to use as a filler
    ss << std::setw(8) << std::setfill('0');
    // | Length  |    Length    |
    // | (bytes) | (hex digits) |
    // |---------|--------------|
    // |    4    |      8       | integer giving the low 32 bits of the time
    ss << uuid_.time_low << "-";
    // |    2    |      4       | integer giving the middle 16 bits of the time
    ss << std::setw(4) << std::setfill('0');
    ss << uuid_.time_mid << "-";
    // |    2    |      4       | 4-bit "version" in the most significant bits,
    // |         |              | followed by the high 12 bits of the time
    ss << std::setw(4) << std::setfill('0');
    ss << uuid_.time_hi_and_version << "-";
    // |    2    |      4       | 1-3 bit "variant" in the most significant
    // |         |              | bits, followed by the 13-15 bit clock sequence
    ss << std::setw(4) << std::setfill('0');
    ss << uuid_.clock_seq << "-";
    // |    6    |      12      | the 48-bit node id
    constexpr auto nodeArraySize = sizeof(uuid_.node) / sizeof(*uuid_.node);
    for (size_t i = 0; i < nodeArraySize; ++i)
    {
        ss << std::setw(4) << std::setfill('0');
        ss << uuid_.node[i];
    }

    this->uuidCanonicalString = ss.str();
    this->isEmpty = false;
}

std::array<uint8_t, UUID::UUID_Size> UUID::AsArray() const
{
    return this->uuid;
};

std::string const& UUID::AsCanonicalString() const
{
    return this->uuidCanonicalString;
}

std::string UUID::AsString() const
{
    std::string str {this->uuidCanonicalString};

    if (this->formatFlags & static_cast<int>(Format::Microsoft))
    {
        str = "{" + str + "}";
    }

    return this->ApplyCharacterFormat(str);
}

std::wstring UUID::AsWString() const
{
    mbstate_t state = std::mbstate_t ();;
    size_t characterCount = 0;
    auto sourceString = this->uuidCanonicalString.c_str();
    mbsrtowcs_s(&characterCount, nullptr, 0, &sourceString, 0, &state);
    std::vector<wchar_t> wchar_tCharacters(characterCount);
    auto sourceStringLength = this->uuidCanonicalString.length();
    mbsrtowcs_s(&characterCount,
                    wchar_tCharacters.data(),
                    characterCount,
                    &sourceString,
                    sourceStringLength,
                    &state);

    std::wstring str (wchar_tCharacters.data());
    if (this->formatFlags & static_cast<int>(Format::Microsoft))
    {
        str = L"{" + str + L"}";
    }

    return this->ApplyCharacterFormat(str);
}

void UUID::ClearFormat()
{
    this->formatFlags = 0b0000'0000;
}

void UUID::Format(int formatFlags)
{
    this->formatFlags = formatFlags;
}


bool UUID::Empty() const
{
    return this->isEmpty;
}
