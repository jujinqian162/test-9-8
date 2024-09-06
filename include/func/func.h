#include "type_traits"
#include <cstdlib>
#include "iostream"
int add(int a, int b);

template<typename T>
std::enable_if_t<std::is_floating_point_v<T>, bool> 
equal(T f1, T f2){
    if (std::abs(f1 - f2) <  0.00001 ){
        return true;
    } 
    else return false;
}

template <typename T>
std::enable_if_t<!std::is_floating_point_v<T>, bool> 
equal(T i1, T i2){
    return i1 == i2;
}