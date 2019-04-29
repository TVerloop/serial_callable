/**
 * @file    serial_callable.hpp
 * @author   <tom@vivobook>
 * @version 1.0
 * @date    04-02-2019
 *
 *
 */

#ifndef CALLABLE_HPP__
#define CALLABLE_HPP__

#include <serialize.hpp>

namespace serial {

template<typename C>
struct callable : public callable<decltype(&C::operator())> {

    constexpr callable(C c) : callable<decltype(&C::operator())>(c) {

    }
};

template<typename R, typename ...A>
struct callable<R(*)(A...)> {

    using callable_type = R(*)(A...);

    callable_type callable_;

    R operator()(A... a) const {
        return callable_(a...);
    }

    std::string operator() (std::string input) const {
        return serialize(callable_(deserialize<A>(input)...));
    }

    constexpr callable(callable_type c) : callable_(c) {

    }

};

template<typename C, typename R, typename ...A>
struct callable<R(C::*)(A...)> {

    using callable_type = C;

    callable_type callable_;

    R operator()(A... a) const {
        return callable_(a...);
    }

    std::string operator() (std::string input) const {
        return serialize(callable_(deserialize<A>(input)...));
    }

    constexpr callable(callable_type c) : callable_(c) {

    }

};

template<typename C, typename R, typename ...A>
struct callable<R(C::*)(A...) const> {

    using callable_type = C;

    callable_type callable_;

    R operator()(A... a) const {
        return callable_(a...);
    }

    std::string operator() (std::string input) const {
        return serialize(callable_(deserialize<A>(input)...));
    }

    constexpr callable(callable_type c) : callable_(c) {

    }

};

}; // serial

#endif // CALLABLE_HPP__
