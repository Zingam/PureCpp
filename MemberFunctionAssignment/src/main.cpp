#include <iostream>
#include <vector>

#include "classes.h"

int main()
{
    std::cout << "Creating object(0)" << std::endl;
    A object(0);
    std::cout << "object.getPrivateVariable() => " << object.getPrivateIntField() << std::endl;

    std::cout << "Assigning to a member function: object.setPrivateIntField() = 5;" << std::endl;
    object.setPrivateIntField() = 5;

    std::cout << "object.getPrivateVariable() => " << object.getPrivateIntField() << std::endl;

    std::cout << "object.setPrivateIntField(10)" << std::endl;
    object.setPrivateIntField(10);

    std::cout << "object.getPrivateVariable() => " << object.getPrivateIntField() << std::endl;

    return 0;
}

