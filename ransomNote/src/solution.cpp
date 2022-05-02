#include "solution.h"

#include <array>
#include <string>

namespace Solution {

bool Solution::canConstruct(string ransomNote, string magazine) {
    std::array<int, 26> letter_frequency{};

    for( char const& letter : magazine ) {
        letter_frequency[letter - 'a']++;
    }

    for( char const& letter : ransomNote) {
        if (letter_frequency[letter - 'a'] == 0) {
            return false; // We run out of letters.

        }
    
        // save the position of the last time the charater was used.
        letter_frequency[letter - 'a']--; 
    }

    return true;
}

} // namespace Solution