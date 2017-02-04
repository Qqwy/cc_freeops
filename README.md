# C++ Free Operators
An implementation of automatic free binary operator generation when their respective compound operators are known.

## How does it work:

The following nice Template Metaprogramming techniques are used:

- `decltype(a, b, c)` will return the type of the expression `c` unless either `a` or `b` do not type check.
In this latter case, the whole template definition that `decltype` is part of will be skipped by the compiler: [SFINAE](https://en.wikipedia.org/wiki/Substitution_failure_is_not_an_error).
In `a` and sometimes `b` we fill in expressions that the operands of the function should have, if we want the body to typecheck.

- `std::enable_if<std::is_base<FreeOperators, T>, decltype(...)>` This ensures that the given definition is only considered (again using SFINAE) if the type `T` is a child class of `Operators`,
to ensure that only those classes will have free operators added to them.

Together, this ensures that an implementation of `operator+` like this:

```c++
template<typename T>
inline auto operator+(T lhs, T const &rhs) ->
    typename std::enable_if<
    std::is_base_of<FreeOperators, T>::value,
    decltype(
        lhs.operator+=(rhs),
        std::declval<T>()
        )
    >::type
{
    lhs += rhs;
    return std::move(lhs);
}
```

is only added to a class `Foo` if:

- `Foo` has a function `operator+=` that takes a const reference as argument.
- `Foo` is a child class of `FreeOperators`.


This has been used in this simple library to define the following operators:

- `+` if `+=` is defined.
- `-` if `i=` is defined.
- `*` if `*=` is defined.
- `/` if `/=` is defined.
- `%` if `%=` is defined.
- `^` if `^=` is defined.
- `&` if `&=` is defined.
- `|` if `|=` is defined.
- `<<` if `<<=` is defined.
- `>>` if `>>=` is defined.
- `>>` (stream extraction) if `extract_from(std::istream &)` is defined.
- `<<` (stream insertion) if `insert_into(std::ostream &)` is defined.
