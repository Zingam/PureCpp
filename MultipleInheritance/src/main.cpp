#include "classes.h"

int main()
{
    Base1* b1 = new Derived1();
    Base2* b2 = new Derived1();
    Derived1* d1 = new Derived1();
    Derived2* d2 = new Derived2();

    b1->Say();
    b2->Say();
    b1 = d1;
    b2 = d2;
    b1->Say();
    b2->Say();
    b1 = d2;
    b1->Say();
}

