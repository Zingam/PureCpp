#include <iostream>
#include <vector>
#include <memory>

#if __cplusplus > 199711L
    #define CPLUSPLUS11
#endif // __cplusplus < 199711L

template <typename T>
void delete_safe(T t)
{
    delete t;
#if defined CPLUSPLUS11
    t = nullptr;
#else
    t = 0;
#endif // CPLUSPLUS11
    std::cout << "It got popped!" << std::endl;
}


using namespace std;

class Animal
{
public:
    Animal() {
        ++(this->animalNumber);
        cout << "I made animal number: " << this->animalNumber << endl;
    }

    virtual ~Animal() { cout << "Killing the animal" << endl; }

private:
    static int animalNumber;

public:
    virtual void doSomething() { cout << "I am an animal!" << endl; }

protected:
    int getAnimalNumber() {
        return this->animalNumber;
    }

    void live() {
        makeSound();
    }

    virtual void makeSound() {
        cout << "The animal says: ";
    }
};

int Animal::animalNumber = 0;

class Cat : public Animal
{
public:
    Cat() :
        animalNumber(Animal::getAnimalNumber())
    { cout << "I made a cat" << endl; }

    virtual ~Cat() { cout << "My cat number " << animalNumber << " died... :(" << endl; }

private:
    const int animalNumber;

public:
    virtual void doSomething() {
        live();
    }

private:
    virtual void makeSound() {
        Animal::makeSound();
        cout << "Meow" << endl;
    }
};

class Dog: public Animal
{
public:
    Dog() :
        animalNumber(Animal::getAnimalNumber())
    { cout << "I made a dog!" << endl; }


    Dog(int i) :
        i(i),
        animalNumber(Animal::getAnimalNumber())
    {
#if defined CPLUSPLUS11
        this->i += offset;
#endif
        cout << "I made a dog!" << endl;
        cout << "It has an external number: " << i << endl;
        cout << "It has an internal number: " << this->i << endl;
#if defined CPLUSPLUS11
        cout << "It has an offset of: " << offset;
#endif //
        cout << endl;
    }


    virtual ~Dog() { cout << "My dog number " << animalNumber << " died... :(" << endl; }

private:
    int i;
#if defined CPLUSPLUS11
    int offset = 1; // C++ 11
#endif
    const int animalNumber;

public:
    virtual void doSomething() {
        live();
    }

private:
    virtual void makeSound() {
        Animal::makeSound();
        cout << "Bau" << endl;
    }
};

class Mouse : public Animal
{
public:
    Mouse() :
        animalNumber(Animal::getAnimalNumber())
    { cout << "I made a mouse!" << endl; }

    virtual ~Mouse() { cout << "My mouse number " << animalNumber << " died... :(" << endl; }

private:
    const int animalNumber;

public:
    virtual void doSomething() {
        live();
    }

private:
    virtual void makeSound() {
        Animal::makeSound();
        cout << "Squeeek" << endl;
    }
};


int main()
{
#if defined CPLUSPLUS11
    cout << "God bless C++ 11" << endl << endl;
#endif

    cout << ">>> Cat and Dog play:" << endl;

    Dog dog;
    dog.doSomething();
    Cat cat;
    cat.doSomething();

    Animal* animal0;
    Animal* animal1;
    Animal* animal2;

    animal0 = &dog;
    animal1 = &dog;
    animal2 = &cat;

    cout << endl << ">>> animal00, animal01 and animal 02 doing something:" << endl;

    static_cast<Dog*>(animal0)->doSomething();
    (*static_cast<Dog*>(animal0)).doSomething(); // Derefernce operator *
    static_cast<Dog*>(animal1)->doSomething();
    static_cast<Cat*>(animal2)->doSomething();

    cout << endl << ">>> Constructing animals in pointers: " << endl;
    vector<Animal*> animalsInPointers;
    animalsInPointers.push_back(new Dog());
    animalsInPointers.push_back(new Cat());
    animalsInPointers.push_back(new Dog(2));
    animalsInPointers.push_back(new Dog());
    animalsInPointers.push_back(new Dog());
    animalsInPointers.push_back(new Cat());
    animalsInPointers.push_back(new Dog(1));
    animalsInPointers.push_back(new Mouse());

#if defined CPLUSPLUS11
    cout << endl << ">>> Counting the animals:" << endl;
    for (auto animal: animalsInPointers) {
        animal->doSomething();
    }
#endif

    cout << endl << ">>> Send animals to Heaven:" << endl;
    do {
        Animal* animal = animalsInPointers.back();
        delete_safe(animal);
        animalsInPointers.pop_back();
    } while (!animalsInPointers.empty());

    cout << endl << ">>> Lets plays smartly! Put all animals in smart pointers:" << endl;
    vector<shared_ptr<Animal>> animalsInSmartPointers;
    animalsInSmartPointers.push_back(make_shared<Mouse>(Mouse()));
    animalsInSmartPointers.push_back(make_shared<Mouse>(Mouse()));
    animalsInSmartPointers.push_back(make_shared<Mouse>(Mouse()));
    animalsInSmartPointers.push_back(make_shared<Mouse>(Mouse()));
    animalsInSmartPointers.push_back(make_shared<Dog>(Dog()));
    animalsInSmartPointers.push_back(make_shared<Dog>(Dog(5)));

#if defined CPLUSPLUS11
    cout << endl << ">>> Counting the smart animals:" << endl;
    for (auto animal: animalsInSmartPointers) {
        animal->doSomething();
    }
#endif

    cout << endl << ">>> Commmit a mouse experiment!" << endl;
    shared_ptr<Animal> shared_ptr_Mouse01;
    cout << "Make Mouse 1:" << endl;
    shared_ptr_Mouse01 = shared_ptr<Animal>(new Mouse());
    shared_ptr<Animal> shared_ptr_Mouse02;
    cout << "Make Mouse 2:" << endl;
    shared_ptr_Mouse02 = make_shared<Animal>(Mouse());
    shared_ptr<Animal> shared_ptr_Mouse03;
    cout << "Make Mouse 3:" << endl;
    shared_ptr_Mouse03 = shared_ptr<Mouse>(new Mouse());
    shared_ptr<Animal> shared_ptr_Mouse04;
    cout << "Make Mouse 4:" << endl;
    shared_ptr_Mouse04 = make_shared<Mouse>(Mouse());
    shared_ptr<Mouse> shared_ptr_Mouse05;
    cout << "Make Mouse 5:" << endl;
    shared_ptr_Mouse05 = shared_ptr<Mouse>(new Mouse());
    shared_ptr<Mouse> shared_ptr_Mouse06;
    cout << "Make Mouse 6:" << endl;
    shared_ptr_Mouse06 = make_shared<Mouse>(Mouse());


    cout << endl << ">>> Playing with numbers: " << endl;
    int number = 5;
    int* pNumber = &number; // Put address &number of number into pointer pNumber

    cout << "You have: " << *pNumber << " at " << pNumber << endl;  // Dereference operator *

    cout << endl << ">>> Finishing it off!" << endl;

    return 0;
}

