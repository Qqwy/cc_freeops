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
