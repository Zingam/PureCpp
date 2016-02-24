////////////////////////////////////////////////////////////////////////////////
#include <iostream>
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
class BaseClass
{
public:
    BaseClass() :
        id(0)
    {
        std::cout << "Constructing object (no Id)" << std::endl;
    }

    BaseClass(int id)
        : BaseClass()
    {
        this->id = id;

        std::cout << "Costrucing object Id: "
                  << this->getId() << std::endl;
    }

    BaseClass(const BaseClass& baseClass) :
        id(baseClass.id)
    {
        std::cout << "Copying object Id (constructor): "
                  << baseClass.id << std::endl;
    }

    BaseClass& operator= (BaseClass& baseClass)
    {
        std::cout << "Copying object Id (assignment): "
                  << baseClass.id << std::endl;

        return baseClass;
    }

    BaseClass(BaseClass&& baseClass)
    {
        std::cout << "Moving object Id (constructor): "
                  << baseClass.id << std::endl;

        this->id = baseClass.id;
    }

    BaseClass& operator= (BaseClass&& baseClass)
    {
        std::cout << "Moving object Id (assignment): "
                  << baseClass.id << std::endl;

        if (this != &baseClass)
        {
            // Copy the data
            this->id = baseClass.id;
            // Clear the data from the original object
            baseClass.id = 0;
        }

        return *this;
    }

    virtual ~BaseClass()
    {
        std::cout << "Destroying object Id: "
                  << this->getId() << std::endl;
    }

    int getId()
    {
        return this->id;
    }

private:
    int id;
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
void main()
{
    std::cout << "Creating a BaseClass object:" << std::endl;
    BaseClass baseClass(1);

    std::cout << std::endl
              << "Testing object Id: "
              << baseClass.getId() << std::endl;

    std::cout << std::endl
                << "Re-initializing the BaseClass object:" << std::endl;
    baseClass = BaseClass(2);

    std::cout << std::endl
              << "Testing object Id: "
              << baseClass.getId() << std::endl;

    std::cout << "\nAuto-destroying the object on exit:" << std::endl << std:: endl;
}
////////////////////////////////////////////////////////////////////////////////

