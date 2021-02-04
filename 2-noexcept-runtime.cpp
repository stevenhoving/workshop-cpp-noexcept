#include <vector>
#include <fmt/printf.h>

// Shamelessly stolen from https://www.youtube.com/watch?v=AG_63_edgUg

class Foo
{
public:
    Foo()
    {
        fmt::print("Foo()\n");
    }

    Foo(int value)
    {
        fmt::print("Foo({})\n", value);
    }

    Foo(const Foo&)
    {
        fmt::print("operator = (const Foo&)\n");
    }

    Foo & operator = (const Foo&)
    {
        fmt::print("operator = (const Foo&)\n");
        return *this;
    }

    Foo(Foo&&)
    {
        fmt::print("operator = (Foo&&)\n");
    }

    Foo & operator = (Foo&&)
    {
        fmt::print("operator = (Foo&&)\n");
        return *this;
    }

    ~Foo()
    {
        fmt::print("~Foo()\n");
    }
};

int main()
{
    std::vector<Foo> thingy;
    thingy.push_back(1);
    
    return static_cast<int>(thingy.size());
}
