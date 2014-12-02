#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include <type_traits>

// This operator template will be enabled only if the type is enum.
// This is achieved by using std::enable_if from <type_traits>.
// If the type is enum std::is_enum true and std:enable_if enables
// the operator template during compilation for the corresponding types.
template<typename T>
typename std::enable_if<std::is_enum<T>::value, std::ostream&>::type
operator << (std::ostream& stream, const T& object)
{
    stream << static_cast<int>(object);

    return stream;
}

#endif // OPERATOR_H
