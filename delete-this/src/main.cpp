// Example program
#include <cassert>
#include <iostream>
#include <string>


class TheClass
{
public:
    TheClass(std::string name)
        : name(name)
    {
        std::cout << "\tObject \"" << this->name << "\" of class TheClass was constructed" << std::endl;
    }

    virtual ~TheClass()
    {
        std::cout << "\tObject \"" << this->name << "\" of class TheClass was destructed" << std::endl << std::endl;
    }

    void DeleteMe()
    {
        std::cout << "\tDelete the class from within!" << std::endl;
        delete this;
    }

    void ToString()
    {
        std::cout << "\tObject \"" << this->name << "\" of class TheClass" << std::endl;
    }

private:
    std::string name;
};

int main()
{
    std::cout << "\nStep 1.: Create object \"First\":" << std::endl;
    TheClass theClass("First");
    theClass.ToString();
    // Undefined behavior - don't do this. You can use 'delete this' only on object created by 'new'.
    //theClass.DeleteMe();

    std::cout << "\nStep 2.: Create object \"Second\":" << std::endl;
    TheClass* theClassAgain = new TheClass("Second");
    theClassAgain->ToString();
    theClassAgain->DeleteMe();
    assert(nullptr != theClassAgain);
    // Calling a method on a 'null pointer' is 'undefined behavior'.
    //theClassAgain->ToString();
    // Deleting an invalid pointer is 'undefined behavior'.
    //delete theClassAgain;
    theClassAgain = nullptr;
    // Calling a method on a 'null pointer' is an 'undefined behavior'.
    //theClassAgain->ToString();
    // Deleting a 'null pointer' gets ignored and there is no need to check a 'null pointer' gets deleted.
    delete theClassAgain;

    std::cout << "\ntheClass(\"First\") object will be destroyed on exit:" << std::endl;

    return 0;
}
