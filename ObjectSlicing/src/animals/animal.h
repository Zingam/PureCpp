#ifndef ANIMAL_H
#define ANIMAL_H

#include "../__rm_utilities__/__rm_utilities__.h"

namespace rm {
    namespace animals {
        class Animal;
    }
}


///
/// \brief The Animal class
///
class rm::animals::Animal {
public:
    Animal() {
        std::cout << "Making animal" << std::endl;
    }
    virtual ~Animal() {
        std::cout << "Send the animal home!" << std::endl;
    }

private:
    // To prevent Object Slicing delete:
    // 1. Copy constructor
    // 2. Copy assignment operator
    // 3. Move constructor
    // 4. Move assignment operator
    COPY_AND_MOVE_DISALLOW(Animal)

public:
    virtual void speak() {
        std::cout << "I am an animal!" << std::endl;
    }
};

#endif // ANIMAL_H
