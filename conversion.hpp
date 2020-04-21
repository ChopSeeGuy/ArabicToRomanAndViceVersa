#pragma once


#include <string>
#include <cstdlib>
#include <stdexcept>
#include <map>
#include <vector>


constexpr static uint16_t maximumValueToConvert = 3999;
constexpr static uint8_t minimumValueToConvert = 1;
const static std::string thousandsRoman[] {"", "M", "MM", "MMM"}; 
const static std::string hundredsRoman[] {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}; 
const static std::string dozensRoman[] {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}; 
const static std::string unityRoman[] {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
static std::map<char, int> romanToArabicNumbers 
{
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};


inline std::string toRoman(const uint16_t &arabicNumber)
{
    if(arabicNumber < minimumValueToConvert or arabicNumber > maximumValueToConvert)
    {
        std::cerr << "toRoman failed in file " << __FILE__ << " at line " <<  __LINE__ << '\n';
        throw std::invalid_argument("Wrong argument passed to 'toRoman' func");
    }

    std::string romanNumber =   thousandsRoman[arabicNumber/1000] + 
                                hundredsRoman[(arabicNumber%1000)/100] + 
                                dozensRoman[(arabicNumber%100)/10] + 
                                unityRoman[arabicNumber%10];

    return romanNumber;

}

inline int fromRoman(const std::string &romanNumber)
{
    uint16_t sum = 0;
    for(int i = 0; i < romanNumber.length(); i++)
    {
        if(romanToArabicNumbers[romanNumber[i]] >= romanToArabicNumbers[romanNumber[i+1]])
        {
            sum += romanToArabicNumbers[romanNumber[i]]; 
        }
        else 
        {
            sum -= romanToArabicNumbers[romanNumber[i]];  
        }
    }

    return sum;
}
