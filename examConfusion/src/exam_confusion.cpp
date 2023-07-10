#include <algorithm>
#include <unordered_map>

#include "exam_confusion.h"

namespace Solution {

static bool testWindowLength(const std::string& answerKey, const size_t& windowLength, const int& maxMoves) {
    std::basic_string_view<char> slidingWindow;
    std::pair<int, int> characterCount;
    auto slidingWindowStart = answerKey.cbegin();
    auto slidingWindowEnd = std::next(slidingWindowStart, windowLength - 1);
    
    slidingWindow = {answerKey.c_str(), windowLength};
    characterCount = {0,0};
    for (const char& character : slidingWindow) {
      switch(character) {
        case 'T':
          characterCount.first++;
          break;
        case 'F':
          characterCount.second++;
          break; 
      }
    }
    
    while (slidingWindowEnd < answerKey.end()) {
      if ( std::min(characterCount.first, characterCount.second) <= maxMoves ) return true;
      *slidingWindowStart == 'T' ? characterCount.first-- : characterCount.second--;
      slidingWindowStart++;
      slidingWindowEnd++;
      *slidingWindowEnd == 'T' ? characterCount.first++ : characterCount.second++;
    }

    return false;
}

int Solution::maxConsecutiveAnswers(const std::string& answerKey, const int& maxMoves) {
  int min = 1;
  int max = std::size(answerKey);
  int windowLength;
  while( min < max) {
    windowLength = max - (max - min) / 2;
    if ( testWindowLength(answerKey, windowLength, maxMoves) ) {
      min = windowLength;
    } else {
      max = windowLength - 1;
    }
  }
  return min;
}

}
