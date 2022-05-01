#include "solution.h"

#include <map>
#include <string>

namespace Solution {

bool Solution::canConstruct(string ransomNote, string magazine) {
    // std::multiset<char> mSet = std::multiset(magazine.cbegin(), magazine.cend());

    std::map<char, std::string::size_type> letter_idx_cache = {
        {'a', 0},
        {'a', 0},
        {'b', 0},
        {'c', 0},
        {'d', 0},
        {'e', 0},
        {'f', 0},
        {'g', 0},
        {'h', 0},
        {'i', 0},
        {'j', 0},
        {'k', 0},
        {'l', 0},
        {'m', 0},
        {'n', 0},
        {'o', 0},
        {'p', 0},
        {'q', 0},
        {'r', 0},
        {'s', 0},
        {'t', 0},
        {'u', 0},
        {'v', 0},
        {'w', 0},
        {'x', 0},
        {'y', 0},
        {'z', 0},
    };

    for( char const& letter : ransomNote) {
        const std::string::size_type cached_letter_idx{ letter_idx_cache[letter] };
        const std::string::size_type letter_idx{ magazine.find(letter, cached_letter_idx) };

        if (letter_idx == std::string::npos) {
            return false; // We run out of letters.

        }
    
        // save the position of the last time the charater was used.
        letter_idx_cache[letter] = letter_idx + 1; 
    }

    return true;
}

} // namespace Solution