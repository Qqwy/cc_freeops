#ifndef _FREE_OPERATORS_H_
#define _FREE_OPERATORS_H_

#include <type_traits>

/*
Trait class.
Any class that derives from FreeOperators
shows its intent to define all free operators
that can be defined for it.
 */
class FreeOperators
{};


// Adds `+` to anything that defines `+=` and inherits from `FreeOperators`.
template<typename T>
inline auto operator+(T &lhs, T const &rhs) ->
typename std::enable_if<
std::is_base_of<FreeOperators, T>::value,
    decltype(
        lhs.operator+=(rhs),
        std::declval<T&>()
        )
    >::type
{
    return lhs += rhs;
}


// Adds `-` to anything that defines `-=` and inherits from `FreeOperators`.
template<typename T>
inline auto operator-(T &lhs, T const &rhs) ->
    typename std::enable_if<
    std::is_base_of<FreeOperators, T>::value,
    decltype(
        lhs.operator-=(rhs),
        std::declval<T&>()
        )
    >::type
{
    return lhs -= rhs;
}

// Adds `*` to anything that defines `*=` and inherits from `FreeOperators`.
template<typename T>
inline auto operator*(T &lhs, T const &rhs) ->
    typename std::enable_if<
    std::is_base_of<FreeOperators, T>::value,
    decltype(
        lhs.operator*=(rhs),
        std::declval<T&>()
        )
    >::type
{
    return lhs *= rhs;
}

// Adds `/` to anything that defines `/=` and inherits from `FreeOperators`.
template<typename T>
inline auto operator/(T &lhs, T const &rhs) ->
    typename std::enable_if<
    std::is_base_of<FreeOperators, T>::value,
    decltype(
        lhs.operator/=(rhs),
        std::declval<T&>()
        )
    >::type
{
    return lhs /= rhs;
}

#include <iostream>

// adds stream insertion to anything that defines `insert_into` and inherits from `FreeOperators`
template<typename T>
inline auto operator<<(std::ostream &os, T const &rhs) ->
    typename std::enable_if<
    std::is_base_of<FreeOperators, T>::value,
    decltype(
        rhs.insert_into(os),
        std::declval<std::ostream&>()
        )
    >::type
{
    rhs.insert_into(os);
    return os;
}

// adds stream extraction to anything that defines `extract_from` and inherits from `FreeOperators`
template<typename T>
inline auto operator>>(std::istream &is, T const &rhs) ->
    typename std::enable_if<
    std::is_base_of<FreeOperators, T>::value,
    decltype(
        rhs.extract_from(is),
        std::declval<std::istream&>()
        )
    >::type
{
    rhs.extract_from(is);
    return is;
}





#endif //_FREE_OPERATORS_H_
