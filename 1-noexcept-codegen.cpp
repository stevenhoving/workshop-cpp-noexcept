#include <string>

/*!
 * Before we start, this is a basics presentation. So I won't be covering the following subjects:
 * - noexcept(noexcept(t))
 * - noexcept(bool) with type_traits
 * - std::move_if_noexcept
 */

/*!
 * Noexcept is a contract between the compiler and the programmer. As the programmer promises
 * the compiler that a specific piece of code will never throw an exception. This allows the compiler
 * to generate much more optimized code than otherwise.
 * If an exception is thrown in a noexcept function std::terminate will be called.
 */

 // good practices

class Foo
{
public:
    Foo(const std::string& name)
        : m_name(name)
    {
    }

    void SetName(const std::string& newName)
    {
        m_name = newName;
    }

    std::string GetName()
    {
        return m_name;
    }

private:
    std::string m_name;
};

int main()
{
    auto foo = Foo{
        "The only reason why this string is so long is because SSO won't kick in"
    };

    return foo.GetName().size();
}