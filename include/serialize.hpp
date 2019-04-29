/**
 * @file    serialize.hpp
 * @author   <tom@vivobook>
 * @version 1.0
 * @date    04-02-2019
 *
 *
 */

#ifndef SERIALIZE_HPP__
#define SERIALIZE_HPP__

namespace serial {

template<typename T>
std::string serialize(T t);

template<>
std::string serialize<int>(int t){
    return std::to_string(t);
}

template<typename T>
T deserialize(const std::string &str);

template<>
char deserialize<char>(const std::string &str) {
    return str[1];
}

template<>
int deserialize<int>(const std::string &str) {
    return std::stoi(str);
}

}; // namespace serial

#endif // SERIALIZE_HPP__
