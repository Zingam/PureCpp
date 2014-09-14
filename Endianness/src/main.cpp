#include <iostream>

bool isCurrentMachineBigEndian()
{
    int number = 1;
    return !(reinterpret_cast<char *>(&number)[0]);
}

int convertCharArrayToInt(char *buffer, int length)
{
    int tempBuffer = 0;

    if (isCurrentMachineBigEndian()) {
        for (int byteIndex = 0; byteIndex < length; byteIndex++)
            (reinterpret_cast<char *>(&tempBuffer))[byteIndex] = buffer[3 - byteIndex];
    }
    else {
        for (int byteIndex = 0; byteIndex < length; byteIndex++)
            (reinterpret_cast<char *>(&tempBuffer))[byteIndex] = buffer[byteIndex];
    }
    return tempBuffer;
}

int main()
{
    if (isCurrentMachineBigEndian())
        std::cout << "Big endian" << std::endl;
    else
        std::cout << "Little endian" << std::endl;

    char buffer[4] = { 255, 3, 0, 0};
    std::cout << convertCharArrayToInt(buffer, 4) << std::endl;

    return 0;
}

