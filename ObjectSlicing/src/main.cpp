/*
 * Object Slicing
 *
 * In object-oriented programming, a subclass typically extends its superclass by defining
 * additional member variables. If a superclass instance is assigned its value from a
 * subclass instance, member variables defined in the subclass cannot be copied, since the
 * superclass has no place to store them. This is a natural and unavoidable consequence of
 * assignment by value from subclass objects.
 *
 */

#include <memory>
#include <iostream>
#include <vector>

#include "__rm_utilities__/__rm_utilities__.h"
#include "animals"

int main()
{
    // These objects will be created then destroyed at program exit
    rm::WaitForKeypress(">>> Create some animals:");
    rm::animals::Animal animal;
    rm::animals::Cat cat;
    rm::animals::Dog dog;

    rm::WaitForKeypress(">>> Make the animals speak:");
    animal.speak();
    cat.speak();
    dog.speak();

    // rm::waitForKeypress(">>> Create animals - this will cause Object Slicing:");
    // OBJECT SLICING
    // To prevent Object Slicing the copy constructor, the copy assignment operator,
    // the move constructor and the move assignment operator have to be deleted
    // When the above mentioned constructors and the respective assignment operators
    // were deleted this will cause a compilation error.
//    std::vector<rm::animals::Animal> slicedAnimals;
//    for (int i = 0; 10 > i; i++) {
//        slicedAnimals.push_back(rm::animals::Dog());
//        slicedAnimals.push_back(rm::animals::Cat());
//    }

//    rm::waitForKeypress(">>> Make the animals speak - Object Slicing:");
//#ifdef CPP11
//    for (rm::animals::Animal& animal: slicedAnimals) {
//        animal.speak();
//    }
//#else
//    for (std::vector<rm::animals::Animal>::iterator currentAnimal = slicedAnimals.begin();
//         currentAnimal != slicedAnimals.end();
//         ++currentAnimal) {
//        currentAnimal->speak();
//    }
//#endif // CPP11

    // This won't compile if the copy constructor, the move constructor were deleted
//    std::vector<Animal> animals;

//    for (int i = 0; 10 > i; i++) {
//        Dog dog;
//        animals.push_back(dog);
//        Cat cat;
//        animals.push_back(cat);
//    }

    // To prevent Object Slicing: use pointers
    std::vector<std::unique_ptr<rm::animals::Animal>> animals;

    rm::WaitForKeypress(">>> Create animals - by using unique_ptr<>:");
    for (int i = 0; 10 > i; i++) {
        std::unique_ptr<rm::animals::Dog> dog(new rm::animals::Dog);
        std::unique_ptr<rm::animals::Cat> cat(new rm::animals::Cat);
        animals.push_back(std::move(dog));
        animals.push_back(std::move(cat));
    }

    rm::WaitForKeypress(">>> Make the animals speak - No Object Slicing:");
#ifdef CPP11
    for (std::unique_ptr<rm::animals::Animal>& animal: animals) {
        animal->speak();
    }
#else
    for (std::vector<rm::animals::Animal>::iterator currentAnimal = animals.begin();
         currentAnimal != animals.end();
         ++currentAnimal) {
        currentAnimal->speak();
    }

#endif // CPP11

    // Cannot copy assign because the Animal's copy constructor is deleted
//    std::vector<std::unique_ptr<rm::animals::Animal>> animalsCopy;
//    animalsCopy = animals;

    // All animal objects will be deleted
    // If they are not deleted in this manner they'll be deleted when the program exits
    rm::WaitForKeypress(">>> Clear vector<> \"animals\" container:");
    animals.clear();

    rm::WaitForKeypress(">>> Exit the program");
    return 0;
}

