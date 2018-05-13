#pragma once

#include "pimpl.hpp"

#include <cassert>
#include <iostream>
#include <string_view>


class Library_Implementation_Win
{
public:
    Library_Implementation_Win (const std::string_view& filename)
        : filename (filename)
    {
        std::cout << "Creating: " << filename << std::endl;
    }

    ~Library_Implementation_Win ()
    {
        std::cout << "Destroying: " << filename << std::endl;
    }

public:
    std::string_view& GetFilename () { return filename; };

private:
    std::string_view filename;
};

using Library_Implementation = Library_Implementation_Win;

class Library
    : implementedBy <Library_Implementation>
{
public:
    Library (const char* filename);
    Library (const std::string_view& filename);

    Library (Library&& library);
    Library& operator= (Library &&);

public:
    std::string_view& GetFilename ();
    bool IsEmpty ();

private:
    bool isEmpty;
};

Library::Library (const char* filename)
    : isEmpty (false)
{
    _ptr = std::make_unique<Library_Implementation> (filename);
}

Library::Library (const std::string_view& filename)
    : isEmpty (false)
{
    _ptr = std::make_unique<Library_Implementation> (filename);
}

Library::Library (Library&& other)
    : isEmpty (true)
{
    if (!other.IsEmpty())
    {
        this->_ptr.reset (other._ptr.release());

        isEmpty = false;
        other.isEmpty = true;
    }
}

Library&
Library::operator= (Library&& other)
{
    if (!other.IsEmpty())
    {
        this->_ptr.reset (other._ptr.release ());

        isEmpty = false;
        other.isEmpty = true;
    }

    return *this;
}

std::string_view&
Library::GetFilename ()
{
    assert (nullptr != _ptr);

    return _ptr->GetFilename ();
}

bool
Library::IsEmpty ()
{
    return isEmpty;
}
