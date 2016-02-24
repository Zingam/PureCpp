////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
class BaseClass
{
public:
    virtual ~BaseClass()
    {
        std::cout << "\tBaseClass destructed" << std::endl;
    }

    static auto Create() -> BaseClass*;

    virtual void ToString() = 0;
    virtual void ToStringConstants()
    {
        std::cout << "|\n-> Calling \"BaseClass::ToStringConstants();\":" << std::endl;
        std::cout << "  Object of class BaseClass" << std::endl;
        std::cout << "    m_protectedContent : " << m_protectedContent << std::endl;
        std::cout << "    m_privateContent   : " << m_privateContent << std::endl;
    }

    void ToStringBaseClassConstants()
    {
        std::cout << "|\n-> Calling \"BaseClass::ToStringBaseClassConstants();\":" << std::endl;
        std::cout << "  Object of class BaseClass" << std::endl;
        std::cout << "    m_protectedContent : " << m_protectedContent << std::endl;
        std::cout << "    m_privateContent   : " << m_privateContent << std::endl;
    }

protected:
    BaseClass()
    {
        std::cout << "\tBaseClass constructed" << std::endl;
    }

protected:
    const std::string m_protectedContent = "BaseClass' protected constant";

private:
    const std::string m_privateContent = "BaseClass' private constant";
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
class SubClass : public BaseClass
{
public:
    SubClass()
    {
        std::cout << "\tSubClass constructed" << std::endl;
    }

    virtual ~SubClass()
    {
        std::cout << "\tSubClass destructed" << std::endl;
    }

    virtual void ToString() final
    {
        std::cout << "|\n-> Calling \"SubClass::ToString();\":" << std::endl;
        std::cout << "  Object of class SubClass (short)" << std::endl;
    }

    virtual void ToStringConstants() final
    {
        std::cout << "|\n-> Calling \"SubClass::ToStringConstants();\":" << std::endl;
        std::cout << "  Object of class SubClass (complete):" << std::endl;
        std::cout << "    m_protectedContent : " << m_protectedContent << std::endl;
        std::cout << "    m_privateContent   : " << m_privateContent << std::endl;
    }

    virtual void ToStringBaseClassConstants() final
    {
        std::cout << "|\n-> Calling \"SubClass::ToStringBaseClassConstants();\":" << std::endl;
        std::cout << "  Object of class SubClass (complete):" << std::endl;
        std::cout << "    m_protectedContent : " << m_protectedContent << std::endl;
        std::cout << "    m_privateContent   : " << m_privateContent << std::endl;
    }

protected:
    const std::string m_protectedContent = "SubClass' protected constant";

private:
    const std::string m_privateContent = "SubClass' private constant";
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
auto BaseClass::Create() -> BaseClass*
{
    BaseClass* baseClass = new SubClass();

    return baseClass;
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
template <typename T>
auto SaveDelete(T*& object) -> void
{
    delete object;
    object = nullptr;
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
int main()
{
    std::cout << "Creating a SubClass object by a factory function:" << std::endl;
    BaseClass* baseClass = BaseClass::Create();

    baseClass->BaseClass::ToStringConstants();
    // Not a virtual in BaseClass:
    baseClass->ToStringBaseClassConstants();

    SubClass* subClass = static_cast<SubClass*> (baseClass);
    // Virtual in SubClass:
    subClass->ToStringBaseClassConstants();

    // Possible implicit convertion
    BaseClass* baseClassPtr = subClass;
    baseClassPtr->ToString();
    // Impossible implicit convertion: "error: invalid conversion from 'BaseClass*' to 'SubClass*'"
    //SubClass* subClassPtr = baseClass;
    //subClassPtr->ToString();

    baseClass->ToString();
    baseClass->ToStringConstants();

    std::cout << "\nDeleting the object on exit:" << std::endl;
    SaveDelete(baseClass);
}
////////////////////////////////////////////////////////////////////////////////
