class Base1
{
public:
    Base1() {}
    virtual ~Base1() {}

public:
    virtual void Say() = 0;
};

class Base2
{
public:
    Base2() {}
    virtual ~Base2() {}

public:
    virutal void Say() = 0;
}

class Derived1
    : public Base1, Base2
{
public:
    void Say() final
    {
        std::cout << "I am derived" << std::endl;
    }
}

int main()
{
    Base1* b1 = new Derived();
    Base2* b2 = new Derived();
    Derived* d = new Derived();

    b1->Say();
    b2->Say();
    d->Say();
}