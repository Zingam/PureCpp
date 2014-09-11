#ifndef DOG_H
#define DOG_H

#include "../__rm_utilities__/__rm_utilities__.h"
#include "animal.h"


namespace rm {
    namespace animals {
        class Dog;
    }
}


///
/// \brief The Dog class
///
class rm::animals::Dog : public rm::animals::Animal {
public:
    Dog() {
        std::cout << "Making dog" << std::endl;
    }

    virtual ~Dog() {
        std::cout << "Send the dog home!" << std::endl;
    }

protected:
    // To prevent Object Slicing delete:
    // 1. Copy constructor
    // 2. Copy assignment operator
    // 3. Move constructor
    // 4. Move assignment operator
    COPY_AND_MOVE_ALLOW(Dog)

public:
    virtual void speak() {
        std::cout << "I am a dog!" << std::endl;
    }
};

#endif // DOG_H
