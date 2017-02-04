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
