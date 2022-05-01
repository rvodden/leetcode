#include "solution.h"

#include <map>
#include <string>

namespace Solution {

bool Solution::canConstruct(string ransomNote, string magazine) {
    // std::multiset<char> mSet = std::multiset(magazine.cbegin(), magazine.cend());

    std::map<char, int> mMap;

    for( char const& c : magazine ) {
        mMap[c]++;
    }

    for( char const& c : ransomNote ) {
        if (mMap[c] == 0) return false;
        mMap[c]--;
    }

    return true;
}

} // namespace Solution