#include <iostream>
#include <string>

#include "constants/enums.h"
#include "operators/operator.h"


int main()
{
    // Test the overloaded operator <<
    std::cout << "Color::red                    << " << Color::red << std::endl;
    std::cout << "Color::green                  << " << Color::green << std::endl;
    std::cout << "Color::blue                   << " << Color::blue << std::endl;
    std::cout << "Angles::degree000             << " << Angles::degrees000 << std::endl;
    std::cout << "Angles::degree001             << " << Angles::degrees001 << std::endl;
    std::cout << "Angles::degree002             << " << Angles::degrees002 << std::endl;
    std::cout << "Angles::degree180             << " << Angles::degrees180 << std::endl;
    std::cout << "Angles::degree181             << " << Angles::degrees181 << std::endl;
    std::cout << "Angles::degree182             << " << Angles::degrees182 << std::endl;
    std::cout << "Angles::degree275             << " << Angles::degrees275 << std::endl;

    // Do the above by static_cast
    std::cout << "static_cast<int>(Color::red)   = " << static_cast<int>(Color::red) << std::endl;
    std::cout << "static_cast<int>(Color::green) = " << static_cast<int>(Color::green) << std::endl;
    std::cout << "static_cast<int>(Color::blue)  = " << static_cast<int>(Color::blue) << std::endl;

    // Test if the overloaded operator << messes with the other overloads
    std::cout << "string                        << " << std::string("This is a <string>") << std::endl;
    std::cout << "char*                         << " << "This is a C char* string" << std::endl;
    std::cout << "int                           << " << 1 << std::endl;

    return 0;
}

