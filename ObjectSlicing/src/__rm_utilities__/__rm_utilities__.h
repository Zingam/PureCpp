#ifndef __RM_UTILITIES___H
#define __RM_UTILITIES___H

#include <iostream>
#include <string>


namespace rm {
    void WaitForKeypress(std::string message);
}

// MARCRO: Define C++11 macro if available
#if __cplusplus > 199711L
#define CPP11
#endif

#if defined CPP11
    #define KEYWORD_DEFAULT = default
    #define KEYWORD_DELETE = delete
#else
    #define KEYWORD_DEFAULT
    #define KEYWORD_DELETE
#endif // defined CPP11

// MACRO: Disable copy and move semantics
#define COPY_AND_MOVE_DISALLOW(ClassName) \
    ClassName(const ClassName&) KEYWORD_DELETE;            /* Copy constructor */ \
    ClassName& operator=(const ClassName&) KEYWORD_DELETE; /* Copy assignment operator */ \
    ClassName(ClassName &&) KEYWORD_DELETE;                /* Move constructor */ \
    ClassName& operator=(ClassName&&) KEYWORD_DELETE;      /* Move assignment operator */

// MACRO: Enable copy and move semantics
#define COPY_AND_MOVE_ALLOW(ClassName) \
    ClassName(const ClassName&) KEYWORD_DEFAULT;            /* Copy constructor */ \
    ClassName& operator=(const ClassName&) KEYWORD_DEFAULT; /* Copy assignment operator */ \
    ClassName(ClassName &&) KEYWORD_DEFAULT;                /* Move constructor */ \
    ClassName& operator=(ClassName&&) KEYWORD_DEFAULT;      /* Move assignment operator */


///
/// \brief waitForKeypress
/// \param message
/// Displays a message and waits for a keypress
void rm::WaitForKeypress(std::string message) {
    std::cout << std::endl << message << std::endl << "    ";
    system("pause");
    std::cout << std::endl;
}

#endif // __RM_UTILITIES___H
