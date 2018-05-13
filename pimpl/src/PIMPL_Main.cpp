
#include "Library.hpp"

#include <Windows.h>


int main (void)
{
    Library l1 { "OpenGL" };

    Library l2 { std::move (l1) };

    Library l3 = std::move (l2);

    Library l4 { "DirectX" }; 
    l4 = std::move (l1);

    if (!l1.IsEmpty())
        std::cout << "Filename 1 is: " << l1.GetFilename () << std::endl;
    if (!l2.IsEmpty ())
        std::cout << "Filename 2 is: " << l2.GetFilename () << std::endl;
    if (!l3.IsEmpty ())
        std::cout << "Filename 3 is: " << l3.GetFilename () << std::endl;
    if (!l4.IsEmpty ())
        std::cout << "Filename 4 is: " << l4.GetFilename () << std::endl;

    l4 = std::move (l3);

    if (!l3.IsEmpty ())
        std::cout << "Filename 3 2 is: " << l3.GetFilename () << std::endl;
    if (!l4.IsEmpty ())
        std::cout << "Filename 4 2 is: " << l4.GetFilename () << std::endl;
}
