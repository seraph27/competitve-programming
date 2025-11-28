//prvalue, xvalue, lvalue, glvalue, rvalue

#include <type_traits>
#include <utility>

template<typename T> struct is_rvalue : std::true_type {};
template<typename T> struct is_rvalue<T&> : std::false_type {};
template<typename T> struct is_rvalue<T&&> : std::false_type {};

template<typename T> struct is_lvalue : std::false_type {};
template<typename T> struct is_lvalue<T&> : std::true_type {};
template<typename T> struct is_lvalue<T&&> : std::false_type {};

template<typename T> struct is_xvalue : std::false_type {};
template<typename T> struct is_xvalue<T&> : std::false_type {};
template<typename T> struct is_xvalue<T&&> : std::true_type {};

using namespace std;
void solve() {
    int a = 10; // a is lvalue
    int &b = a;
    int &&x = {std::move(a)}; // type of x is rvalue reference but x itself is lvalue
    static_assert(is_lvalue<decltype((a))>::value);
    static_assert(is_lvalue<decltype(b)>::value);
    //static_assert(is_lvalue<decltype(a)>::value); // error: decltype(a) is int, not int&
    static_assert(std::is_lvalue_reference_v<decltype(b)>);

    static_assert(is_xvalue<decltype(std::move(a))>::value);
}



int main() {
    return 0;
}
