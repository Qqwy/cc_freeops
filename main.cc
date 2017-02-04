#include "free_operators/free_operators.h"

// example class, inline for brevity
class Foo : public FreeOperators
{
    int d_data = 0;
public:
    Foo(int data)
    :
        d_data(data)
    {};

    Foo & operator +=(Foo const &other)
    {
        d_data += other.d_data;
        return (*this);
    }

    Foo & operator /=(Foo const &other)
    {
        d_data /= other.d_data;
        return (*this);
    }


    void insert_into(std::ostream &out) const
    {
        out << '[' << d_data << ']';
    }
};

int main()
{
    Foo bar{1};
    Foo baz{2};
    Foo qux = bar + baz / baz;
    std::cout << qux << '\n';
}
