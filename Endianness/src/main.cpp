#include <iostream>

///
/// \brief isCurrentMachineBigEndian
/// \return true if machine is Big Endian
///
/// A word is defined as a 32 bit quantity, written
/// as 90AB12CD. So, the 4 bytes are: 90, AB, 12, CD
/// where each byte requires 2 hex digits.
///
/// In Big Endian, you store the most significant
/// byte in the smallest address.
///
/// In Little Endian, you store the least significant
/// byte in the smallest address.
///
///            Big Endian   Little Endian
///   Address     Value        Value
///      1000       90           CD
///      1001       AB           12
///      1002       12           AB
///      1003	    CD           90
///
///      High     0x0001b      0x0000b
///      Low      0x0000b      0x0001b
///
///                  High byte  Low byte
///   array          [0]        [1]
///   Big Endian     0x0001b    0x0000b
///   Little Endian  0x0000b    0x0001b
///
///   0000 0000 0000 0000  0000 0000 0000 0000
bool isCurrentMachineBigEndian()
{
    int number = 1;
    // 0x401606  <+0x0006>        c7 45 f8 01 00 00 00  movl   $0x1,-0x8(%ebp)

    //int number2 = 0xF4F3F2F1;
    // 0x40160d  <+0x000d>        c7 45 fc f1 f2 f3 f4  movl   $0xf4f3f2f1,-0x4(%ebp)

    int number3 = 0x87654321;
    // 0x40160d  <+0x000d>        c7 45 fc 21 43 65 87  movl   $0x87654321,-0x4(%ebp)

    char reinterpreted = (char) number3;
    char reinterpreted2 = static_cast<char>(number3);
    char reinterpreted_lo = reinterpret_cast<char*>(&number3)[0];
    char reinterpreted_hi = reinterpret_cast<char*>(&number3)[1];

    std::cout << "sizeof(int) =" << sizeof(int);
    std::cout << "sizeof(char) = " << sizeof(char);

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

