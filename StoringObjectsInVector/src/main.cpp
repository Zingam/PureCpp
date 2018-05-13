////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
class BaseClass
{
public:
    BaseClass(std::string name);
//    BaseClass(BaseClass&& instance);
    ~BaseClass();

protected:
    std::string name;
};

BaseClass::BaseClass(std::string name)
    : name(name)
{
    std::cout << "\tCreated:\tinstance of class BaseClass -> " << this->name
              << std::endl;
}

//BaseClass::BaseClass(BaseClass &&instance)
//    : name(instance.name)
//{
//    std::cout << "\tMoved:\t\tinstance of class BaseClass -> " << this->name
//              << std::endl;
//}

BaseClass::~BaseClass()
{
    std::cout << "\tDestroyed:\tinstance of class BaseClass -> " << this->name
              << std::endl;
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
class DerivedClass : public BaseClass
{
public:
    DerivedClass(std::string name);
//    DerivedClass(DerivedClass&& instance);
    ~DerivedClass();
};

DerivedClass::DerivedClass(std::string name)
    : BaseClass(name)
{
    std::cout << "\tCreated:\tinstance of class DerivedClass -> " << BaseClass::name
              << std::endl;
}

//DerivedClass::DerivedClass(DerivedClass&& instance)
//    : BaseClass(instance.name)
//{
//    std::cout << "\tMoved:\t\tinstance of class DerivedClass -> " << BaseClass::name
//              << std::endl;
//}

DerivedClass::~DerivedClass()
{
    std::cout << "\tDestroyed:\tinstance of class DerivedClass -> " << BaseClass::name
              << std::endl;
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{

    std::vector<BaseClass> baseClasses;
    std::cout << "\nCreating: BaseClass instance 1:" << std::endl;
    baseClasses.push_back(BaseClass("BaseClass instance 1"));
    std::cout << "\nCreating: DerivedClass instance 1:" << std::endl;
    baseClasses.push_back(DerivedClass("DerivedClass instance 1"));

    std::cout << "\nCreating: DerivedClass instance 2:" << std::endl;
    std::vector<DerivedClass> derivedClasses;
    // Can't convert BaseClass to DerivedClass
    //derivedClasses.push_back(BaseClass("BaseClass instance 2"));
    derivedClasses.push_back(DerivedClass("DerivedClass instance 2"));

     std::cout << "\nInstances should be destroyed automatically:" << std::endl;

    return 0;
}
////////////////////////////////////////////////////////////////////////////////
