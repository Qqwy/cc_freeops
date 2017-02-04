#include <iostream>
#include <type_traits>


class Operators
{};

class Foo : public Operators
{
public:
    int d_data = 0;
    Foo(int data)
        :
        d_data(data)
        {
        };

    Foo & operator +=(Foo &other)
        {
            d_data += other.d_data;
        }
};

// Adds `+` to anything that defines `+=` and inherits from `Operators`.
template<typename T>
auto operator+(T &a, T &b) -> 
    typename std::enable_if<
    std::is_base_of<Operators, T>::value,
    decltype(
        a.operator+=(b), 
        std::declval<T&>()
        )
    >::type
{
    return a += b;
}


int main() {
    Foo bar{1};
    Foo baz{2};
    Foo qux = bar + baz;
    std::cout << qux.d_data << '\n';
    std::cout << "Hello World!\n";
}
