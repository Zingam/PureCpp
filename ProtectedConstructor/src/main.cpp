////////////////////////////////////////////////////////////////////////////////
#include <iostream>
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
class BaseClass
{
public:
    virtual ~BaseClass();

public:
    virtual void ToString();

public:
    static BaseClass* create(int32_t id);

protected:
    BaseClass(int32_t id);

protected:
    int32_t id;
};

BaseClass::BaseClass(int32_t id)
    : id(id)
{
    std::cout << "\tConstructing object of class BaseClass with id: " << this->id
              << std::endl;
}

BaseClass::~BaseClass()
{
    std::cout << "\tDestroying object of class BaseClass with id: " << this->id
              << std::endl << std::endl;
}

void BaseClass::ToString()
{
    std::cout << "\tAn instance of class BaseClass with id: " << this->id
              << std::endl;
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
class SubClass : public BaseClass
{
public:
    SubClass(int32_t);
    virtual ~SubClass();

public:
    void ToString() final;
};

SubClass::SubClass(int32_t id)
    : BaseClass(id)
{
    std::cout << "\tConstructing object of class SubClass with id: " << this->id
              << std::endl;
}

SubClass::~SubClass()
{
    std::cout << "\tDestroying object of class SubClass with id: " << this->id
              << std::endl;
}

void SubClass::ToString()
{
    std::cout << "\tAn instance of class SubClass with id: " << this->id
              << std::endl;
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
BaseClass* BaseClass::create(int32_t id)
{
    BaseClass* baseClass = new SubClass(id);

    return baseClass;
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
void main()
{
    std::cout << "Creating a SubClass object:" << std::endl;
    BaseClass* baseClass = BaseClass::create(1);

    // Cannot create an instance because no public constructor is available
    //BaseClass* baseClassNew = new BaseClass(2);

    std::cout << "\nCall a virtual method:" << std::endl;
    baseClass->ToString();

    std::cout << "\nThe instance of the class SubClass should now be destroyed:"
              << std::endl;
    delete baseClass;
}
////////////////////////////////////////////////////////////////////////////////

