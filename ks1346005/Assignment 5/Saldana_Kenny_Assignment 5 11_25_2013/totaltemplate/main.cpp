/* 
 * File:   main.cpp
 * Author: Kenny Saldana
 * Info: CH 16 problem 5
 *
 * Created on November 25, 2013, 2:32 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    return 0;
}



template <typename T>
struct foo{};

template <typename T>
struct bar{};

template < template < class > class T >
struct MyTemplate
{
    static const bool value = false;
};

template <>
struct MyTemplate<bar>
{
    static const bool value = true;
};


int main(void)
{
    std::cout << std::boolalpha;
    std::cout << MyTemplate<foo>::value << std::endl;
    std::cout << MyTemplate<bar>::value << std::endl;
}