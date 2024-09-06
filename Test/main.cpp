#include "catch2/catch_test_macros.hpp"

#include "func/func.h"
TEST_CASE("add"){
    CHECK(3 == add(1, 2));
}

TEST_CASE("float operator =="){
    float a = 3.032343224;
    float b = 3.032343323;
    CHECK(equal(a, b));
    a = 3.0322;
    b = 3.0323;
    CHECK(!equal(a, b));

}

TEST_CASE("int operator =="){
    int a = 123123;
    int b = 123123;
    CHECK(equal(a, b));
}