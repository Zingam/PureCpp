#ifndef CAT_H
#define CAT_H

#include "../__rm_utilities__/__rm_utilities__.h"
#include "animal.h"


namespace rm {
    namespace animals {
        class Cat;
    }
}


///
/// \brief The Cat class
///
class rm::animals::Cat : public rm::animals::Animal{
public:
    Cat() {
        std::cout << "Making cat" << std::endl;
    }

    virtual ~Cat() {
        std::cout << "Sending the cat home!" << std::endl;
    }

protected:
    // To prevent Object Slicing delete:
    // 1. Copy constructor
    // 2. Copy assignment operator
    // 3. Move constructor
    // 4. Move assignment operator
    COPY_AND_MOVE_ALLOW(Cat)

public:
    virtual void speak() {
        std::cout << "I am a cat!" << std::endl;
    }
};

#endif // CAT_H
