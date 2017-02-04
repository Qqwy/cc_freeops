// Adds `+` to anything that defines `+=` and inherits from `FreeOperators`.
template<typename T>
inline auto operator+(T lhs, T const &rhs) ->
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
