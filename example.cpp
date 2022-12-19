#include <iostream>
#include <string>

#include "EnumArray.h"

// enums must retain their default value
enum class GooID
{
    a,
    b,
    c,
    d,
    SIZE	// last enum value must be exactly this
};

struct Goo
{
    int x, y;

    // operator== must be defined for use of getID()
    const bool operator==(const Goo& other) const
    {
        return
            this->x == other.x &&
            this->y == other.y;
    }
};


template<typename Enum, typename Value>
const constexpr bool testGetID(
    const EnumArray<Enum, Value>& arr, 
    const Enum id, 
    const Value val
)
{
    const bool passed{ arr.getID(val) == id };

    const std::string_view status{ passed ? "passed" : "failed" };

    std::cout << status << " getID() test: " 
        << static_cast<int>(arr.getID(val)) << " == " << static_cast<int>(id)
        << '\n';

    assert(passed);

    return passed;
}

template<typename Enum, typename Value>
const constexpr bool testGetVal(
    const EnumArray<Enum, Value>& arr, 
    const Enum id, 
    const Value val
)
{
    const bool passed{ arr.getVal(id) == val };

    const std::string_view status{ passed ? "passed" : "failed" };

    std::cout << status << " getVal() test: " 
        << arr.getVal(id).x << " == " << val.x << " & "
        << arr.getVal(id).y << " == " << val.y
        << '\n';

    assert(passed);

    return passed;
}

int main()
{
    constexpr Goo GOO1{ 1, 22 };
    constexpr Goo GOO2{ 3, 44 };
    constexpr Goo GOO3{ 5, 66 };
    constexpr Goo GOO4{ 7, 88 };

    EnumArray<GooID, Goo> goos{
        {GooID::a, GOO1},
        {GooID::b, GOO2},
        {GooID::c, GOO3},
        {GooID::d, GOO4},
    };

    // only works if operator== defined for value
    testGetID(goos, GooID::a, GOO1);
    testGetID(goos, GooID::b, GOO2);
    testGetID(goos, GooID::c, GOO3);
    testGetID(goos, GooID::d, GOO4);

    testGetVal(goos, GooID::a, GOO1);
    testGetVal(goos, GooID::b, GOO2);
    testGetVal(goos, GooID::c, GOO3);
    testGetVal(goos, GooID::d, GOO4);
}
