#ifndef CLASSES
#define CLASSES

#include <iostream>
#include <vector>

class Base1
{
public:
    Base1() { std:: cout << "Base1: constructing..." << std::endl; }
    virtual ~Base1() { std:: cout << "Base1: destructing..." << std::endl; }

public:
    virtual void Say() = 0;
    virtual void Sing() = 0;
};

class Base2
{
public:
    Base2() { std:: cout << "Base2: constructing..." << std::endl; }
    virtual ~Base2() { std:: cout << "Base2: destructing..." << std::endl; }

public:
    virtual void Say() = 0;
    virtual void Cry() = 0;
};

class Derived1
    : public Base1
    , public Base2
{
public:
    void Say() final
    {
        std::cout << "Derived1->Say()" << std::endl;
        this->Cry();
        this->Sing();
    }

    void Sing() final
    {
        std::cout << "Derived1->Sing()" << std::endl;
    }

    void Cry() final
    {
        std::cout << "Derived1->Cry()" << std::endl;
    }
};

class Derived2
    : public Base1
    , public Base2
{
public:
    void Say() final
    {
        std::cout << "Derived2->Say()" << std::endl;
    }

    void Sing() final
    {
        std::cout << "Derived2->Sing()" << std::endl;
    }

    void Cry() final
    {
        std::cout << "Derived2->Cry()" << std::endl;
    }
};

#endif // CLASSES

