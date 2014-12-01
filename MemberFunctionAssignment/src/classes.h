#ifndef CLASSES
#define CLASSES

class A
{
public:
    explicit A (const int value) :
        privateIntField(value)
    {}

    int& getPrivateIntField()
    {
        return this->privateIntField;
    }

    // This member function can be assigned to as:
    //        object.setPrivateIntField() = 5;
    // as it returns a reference to the private field.
    int& setPrivateIntField()
    {
        return this->privateIntField;
    }

    void setPrivateIntField(const int& value)
    {
        this->privateIntField = value;
    }

private:
    int privateIntField;
};

#endif // CLASSES

