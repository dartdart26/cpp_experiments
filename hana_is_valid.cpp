#include <iostream>
#include <string>
#include <utility>

#include <boost/hana.hpp>

namespace hana = boost::hana;

using namespace std::string_literals;

struct has
{
    auto to_string() const { return "has to string"s; }
};

struct has_not {};

template <typename T>
struct type_cont
{
    using type = T;
};

template <typename T>
constexpr auto my_type_c = type_cont<T>{};

struct my_op_bool
{
    constexpr operator bool() const { return true; }
};

int main()
{
    auto has_to_string = hana::is_valid([](auto obj) -> decltype(std::declval<decltype(obj)::type>().to_string()){});

    if constexpr(has_to_string(my_type_c<has_not>))
        std::cout << "has" << std::endl;
    else
        std::cout << "doesn't have" << std::endl;

    if constexpr(my_op_bool{})
        std::cout << "my op bool" << std::endl;
}
