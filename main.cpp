#include <iostream>
#include <chrono>
#include "conversion.hpp"



int main()
{
    auto start = std::chrono::steady_clock::now();
    auto roman = toRoman(2);
    auto end = std::chrono::steady_clock::now();
    auto result = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    std::cout << "Roman time: " << result << std::endl;
    std::cout << roman << '\n';    // "XLII"

    auto start1 = std::chrono::steady_clock::now();
    auto arabic = fromRoman(roman);
    auto end1 = std::chrono::steady_clock::now();
    auto result1 = std::chrono::duration_cast<std::chrono::microseconds>(end1-start1).count();
    std::cout << "From roman time: " << result1 << std::endl;
    std::cout << arabic << '\n';   // 42
    return 0;
}