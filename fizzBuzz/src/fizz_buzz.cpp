#include "fizz_buzz.h"

#include <vector>
#include <string>

namespace Solution {

std::vector<std::string> Solution::fizzBuzz(int n) {
    std::vector<std::string> returnList;
    for(int i = 1; i <= n; i++) {
        if (i % 15 == 0) {
            returnList.push_back("FizzBuzz");
            continue;
        }
        
        if (i % 3 == 0) {
            returnList.push_back("Fizz");
            continue;
        }

        if (i % 5 == 0) {
            returnList.push_back("Buzz");
            continue;
        }

        returnList.push_back(std::to_string(i));
    }

    return returnList;
}

} // namespace Solution