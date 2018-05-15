#include "UUID.hpp"

#include <iostream>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// UUID Converter Class
////////////////////////////////////////////////////////////////////////////////
// A universally unique identifier (UUID) is a 128-bit number used to identify
// information in computer systems also known as globally unique identifier
// (GUID).
////////////////////////////////////////////////////////////////////////////////

int main()
{
    std::vector<std::string> uuidStrings {
        {"d5085469-3141-4e23-bf9e-227ec487cc78"},
        {"d445a77d-0c42-497b-8756-cd58f0d9e474"},
        {"b438a74a-d749-4383-a5f9-09b86c79bdfa"},
        {"04261464-fe53-4f53-be58-875929512905"},
        {"d64e6fce-ce7f-46a9-a359-42040949943d"},
        {"d3065692-863b-4434-9a7e-4517bba6259f"},
        {"18297c09-d7d9-4f3c-b87c-657005c3d551"},
        {"d4ae84ec-001c-4c4a-b27f-640726a11f5a"},
        {"0000000c-000c-000a-000f-00000000000a"},
        {"00000000-0000-0000-0000-000000000000"},
    };

    std::cout << "UUID: Testing initialization and conversion:\n";

    std::vector<UUID> uuids_01;
    for (auto& uuidString : uuidStrings)
    {
        uuids_01.push_back(uuidString);
    }

    std::vector<UUID> uuids_02;
    for (auto& uuid : uuids_01)
    {
        uuids_02.push_back(uuid.AsArray());
    }

    for (size_t i = 0; i < uuidStrings.size(); ++i)
    {
        if (uuidStrings[i] == uuids_02[i].AsCanonicalString())
        {
            std::cout << "UUIDs are equal:\n";
        }
        else
        {
            std::cout << "UUIDs are NOT equal: ['_']\n";
        }
        std::cout << "  uuidString[" << i << "]: " << uuidStrings[i] << "\n";
        std::cout << "  uuids_02[" << i << "]:   "
                  << uuids_02[i].AsCanonicalString() << "\n";
    }

    std::cout << "\nUUID: Testing conversion functions:\n";
    auto uuid = uuids_02[0];
    if (!uuid.Empty())
    {
        auto formatFlags = static_cast<int>(UUID::Format::UpperCase);
        uuid.Format(formatFlags);
        std::wcout << "In canonical format:   " << uuid.AsWString() << "\n";

        formatFlags |= static_cast<int>(UUID::Format::Microsoft);
        uuid.Format(formatFlags);
        std::cout << "In Microsoft format:   " << uuid.AsString() << "\n";

        uuid.ClearFormat();
        std::cout << "In the default format: " << uuid.AsString() << "\n";

        std::cout << "As an array:           " << uuid.AsArray().data() << "\n";
    }
    else
    {
        std::cout << "  > ERROR: UUID is not intialized correctly...\n";
    }
}
