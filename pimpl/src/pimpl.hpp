#pragma once

#include <memory>

template <typename ClassName>
class implementedBy
{
protected:
    implementedBy () = default;
    ~implementedBy () = default;

    implementedBy (implementedBy&) = delete;
    implementedBy (implementedBy&&) = default;

    implementedBy& operator= (const implementedBy&) = delete;
    implementedBy& operator= (implementedBy&&) = default;

protected:
    std::unique_ptr<ClassName> _ptr;
};
