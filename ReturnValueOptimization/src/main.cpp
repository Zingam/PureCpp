/*
 * Copy Elision:
 *
 * In C++ computer programming, copy elision refers to a compiler optimization
 * technique that eliminates unnecessary copying of objects. The C++ language
 * standard generally allows implementations to perform any optimization,
 * provided the resulting program's observable behavior is the same as if,
 * i.e. pretending, the program was executed exactly as mandated by the
 * standard.
 *
 *
 * Return Value Optimization:
 *
 * Return value optimization, or simply RVO, is a compiler optimization
 * technique that involves eliminating the temporary object created to hold a
 * function's return value.[1] In C++, it is particularly notable for being
 * allowed to change the observable behaviour of the resulting program.
 *
 *
 * GCC: -fno-elide-constructors
 *
 *     The C++ standard allows an implementation to omit creating a temporary
 *     which is only used to initialize another object of the same type.
 *     Specifying this option disables that optimization, and forces G++ to
 *     call the copy constructor in all cases.
 */

#include <iostream>

class Class
{
public:
    Class()
    {
        std::cout << "An Object was created." << std::endl;
    }

    Class(const Class&)
    {
        std::cout << "A Copy was made." << std::endl;
    }
};

Class makeObject()
{
    return Class();
}

int main()
{
    std::cout << "Hello World!" << std::endl;

    Class object = makeObject();

    return 0;
}

