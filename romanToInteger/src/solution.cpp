#include "solution.h"

#include <map>
#include <iostream>

#define ROMAN_I 1
#define ROMAN_V 5
#define ROMAN_X 10
#define ROMAN_L 50
#define ROMAN_C 100
#define ROMAN_D 500
#define ROMAN_M 1000

namespace Solution {

std::map<char, int> const chars{
    {'I', ROMAN_I},
    {'V', ROMAN_V},
    {'X', ROMAN_X},
    {'L', ROMAN_L},
    {'C', ROMAN_C},
    {'D', ROMAN_D},
    {'M', ROMAN_M}
};

int Solution::romanToInt(string s) {
  int value = 0;

  string::const_iterator chr = s.cbegin();
  string::const_iterator nchr = std::next(chr);

  do {
    const int& val = chars.at(*chr);

    if(nchr == s.end()) {
      value += val;
      break;
    }

    const int& nval = chars.at(*nchr);

    if(val < nval) {
      value += (nval - val);
      if ( (&(*s.end()) - &(*chr)) > 2) {
        std::advance(chr, 2);
        std::advance(nchr, 2);
        continue;
      }
      break;
    }

    value += chars.at(*chr);
    chr++; nchr++;
  } while (chr != s.cend());

  return value;
}

} // namespace Solution