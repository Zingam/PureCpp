#include <iostream>

using namespace std;


class SuperObject
{
public:
    SuperObject() :
        id(0)
    {
        std::cout << "Constructing object (no Id)" << std::endl;
    }

    SuperObject(int id)
        : SuperObject()
    {
        this->id = id;

        std::cout << "Costrucing object Id: "
                  << this->getId() << std::endl;
    }

    SuperObject(const SuperObject& superObject) :
        id(superObject.id)
    {
        std::cout << "Copying object Id (constructor): "
                  << superObject.id << std::endl;
    }

    SuperObject& operator= (SuperObject& superObject)
    {
        std::cout << "Copying object Id (assignment): "
                  << superObject.id << std::endl;

        return superObject;
    }

    SuperObject(SuperObject&& superObject)
    {
        std::cout << "Moving object Id (constructor): "
                  << superObject.id << std::endl;

        this->id = superObject.id;
    }

    SuperObject& operator= (SuperObject&& superObject)
    {
        std::cout << "Moving object Id (assignment): "
                  << superObject.id << std::endl;

        if (this != &superObject)
        {
            // Copy the data
            this->id = superObject.id;
            // Clear the data from the original object
            superObject.id = 0;
        }

        return *this;
    }

    virtual ~SuperObject()
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

int main()
{
    SuperObject superObject(1);
    std::cout << std::endl
              << "Testing object Id: "
              << superObject.getId() << std::endl;

    std::cout << std::endl
                << "Re-initializing the object:" << std::endl;
    superObject = SuperObject(2);
    std::cout << std::endl
              << "Testing object Id: "
              << superObject.getId() << std::endl;

    return 0;
}

