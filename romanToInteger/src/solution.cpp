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

#define ROMAN_IV 4
#define ROMAN_IX 9
#define ROMAN_XL 40
#define ROMAN_XC 90
#define ROMAN_CD 400
#define ROMAN_CM 900

namespace Solution {



int Solution::romanToInt(string s) {
  int value = 0;

  char* chr = s.data();

  do {
    switch(*chr) {
      case 'I':
        if (*(chr + 1) == 'V') {
          value += ROMAN_IV;
          chr++;
          break;
        }
        if (*(chr + 1) == 'X') {
          value += ROMAN_IX;
          chr++;
          break;
        }
        value += ROMAN_I;
        break;
      case 'V':
        value += ROMAN_V;
        break;
      case 'X':
        if (*(chr + 1) == 'L') {
          value += ROMAN_XL;
          chr++;
          break;
        }
        if (*(chr + 1) == 'C') {
          value += ROMAN_XC;
          chr++;
          break;
        }
        value += ROMAN_X;
        break;
      case 'L':
        value += ROMAN_L;
        break;
      case 'C':
        if (*(chr + 1) == 'D') {
          value += ROMAN_CD;
          chr++;
          break;
        }
        if (*(chr + 1) == 'M') {
          value += ROMAN_CM;
          chr++;
          break;
        }
        value += ROMAN_C;
        break;
      case 'D':
        value += ROMAN_D;
        break;
      case 'M':
        value += ROMAN_M;
        break;
    }
    chr++;
  } while (*chr != '\0');

  return value;
}

} // namespace Solution