/**
 * @file    main.cpp
 * @author   <tom@vivobook>
 * @version 1.0
 * @date    17-01-2019
 *
 *
 */

//#include <stdio.h>
//#include <type_traits>
//#include <tuple>
//#include <iostream>
//
//template<typename>
//struct callable_traits;
//
//template<typename R, typename ...A>
//struct callable_traits<R(*)(A...)> {
//    using callable_type = R(*)(A...);
//    using container_type = void;
//    using return_type = R;
//
//    template<size_t I>
//    struct arguments {
//        using type = typename std::tuple_element<I, std::tuple<A...> >::type;
//    };
//};
//
//template<class C, typename R, typename ...A>
//struct callable_traits<R(C::*)(A...)> {
//
//    using callable_type = R(C::*)(A...);
//    using container_type = C;
//    using return_type = R;
//
//    template<size_t I>
//    struct arguments {
//        using type = typename std::tuple_element<I, std::tuple<A...> >::type;
//    };
//};
//
//template<typename C, typename R, typename ...A>
//struct callable_traits<R(C::*)(A...) const> {
//
//    using callable_type = R(C::*)(A...) const;
//    using container_type = C;
//    using return_type = R;
//
//    template<size_t I>
//    struct arguments {
//        using type = typename std::tuple_element<I, std::tuple<A...> >::type;
//    };
//};
//
//
//template <typename C>
//struct callable_traits : public callable_traits<decltype(&C::operator())> {
//
//};
//

#include <stdio.h>
#include <type_traits>
#include <tuple>
#include <iostream>

#include <callable.hpp>

serial::callable ssum([](int a, int b) {
    return a + b;
});

int main() {
    std::cout << ssum("5, 7") << std::endl;
    return 0;
}
