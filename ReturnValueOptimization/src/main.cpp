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
#include <string>

/*
 * Macro to suppress "unused variable compiler warning"
 */
#define UNUSED(identifier) (void)identifier;


class SomeClass
{
public:
    SomeClass()
    {
        std::cout << "An Object was created." << std::endl;
    }

    /*
     * Implicit conversion
     *
     * Implicit conversions are performed whenever an expression of
     * some type T1 is used in context that does not accept that type,
     * but accepts some other type T2, in particular:
     *   - When the expression is used as the argument when calling a
     *     function that is declared with T2 as parameter.
     *   - When the expression is used as an operand with an operator
     *     that expects T2
     *   - When initializing a new object of type T2, including
     *     return statement in a function returning T2.
     *   - When the expression is used in a switch statement (T2 is
     *     integral type)
     *   - When the expression is used in an if statement or a loop
     *     (T2 is bool)
     *
     * explicit specifier
     *
     * Specifies constructors and (since C++11) conversion operators
     * that don't allow implicit conversions or copy-initialization.
     *
     * explicit on a constructor with multiple arguments has no
     * effect, since such constructors cannot take part in implicit
     * conversions. However, for the purpose of implicit conversion,
     * explicit will have an effect if a constructor has multiple
     * arguments and all but one of the arguments has a default value.
     */

    // Constructor that takes a pointer as a parameter
    SomeClass(const SomeClass*)
    {
        std::cout << "SomeClass(const SomeClass*) created implicitly." << std::endl;
    }

    // Alternatively:
//    // Constructor that takes a pointer as a parameter
//    SomeClass(const int*)
//    {
//    }

    // Alternatively:
//    // Constructor that takes a pointer as a parameter
//    SomeClass(const std::string*) {}

    SomeClass(const SomeClass&)
    {
        std::cout << "A Copy was made." << std::endl;
    }
};


SomeClass makeObject()
{
    return SomeClass();
}

/*
 * This function will fail to compile unless a Constructor
 * that takes a pointer as a parameter is defined.
 */
SomeClass makeObject(bool returnsNullptr)
{
    if (!returnsNullptr)
    {
        return SomeClass();
    }
    else
    {
        // Unless the constructor is marked with the explicit
        // specifier, the compiler constructs implicitly an
        // instance of SomeClass() on the stack that takes
        // nullptr as an argument, thus makeObject() returns
        // an instance of SomeClass()
        return nullptr;
    }
}


int main()
{
    std::cout << "Hello World!" << std::endl;

    std::cout << "makeObject() - returns an object" << std::endl;
    SomeClass object = makeObject();

    UNUSED(object)

    std::cout << "makeObject(false) - returns an object" << std::endl;
    SomeClass object1 = makeObject(false);
    std::cout << "makeObject(true) - implicit construction" << std::endl;
    SomeClass object2 = makeObject(true); // returns nullptr

    UNUSED(object1)
    UNUSED(object2)

    return 0;
}

