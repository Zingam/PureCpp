#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include <type_traits>

// This operator template is removed from template resolution by
// leveragine SFINAE (Substitution Failure Is Not An Error).
// The operator template will be only enabled if the type is enum.
// This is achieved by using std::enable_if from <type_traits>.
// If the type is enum std::is_enum true and std:enable_if enables
// the operator template via the return type during compilation.
template<typename T>
typename std::enable_if<std::is_enum<T>::value, std::ostream&>::type
operator << (std::ostream& stream, const T& object)
{
    stream << static_cast<int>(object);

    return stream;
}

#endif // OPERATOR_H
