#include <benchmark/benchmark.h>
#include <malloc.h>

#include "exam_confusion.h"

std::string randomString(int length, const int& maxRepetitions) {
  std::string temporaryString;
  char currentCharacter = 'T';
  
  int repetitions;
  while(length > 0) {
    repetitions = (rand() % std::min(maxRepetitions, length)) + 1;
    temporaryString += std::string(repetitions, currentCharacter);
    currentCharacter = currentCharacter == 'T' ? 'F' : 'T';
    length -= repetitions;
  }
  return temporaryString;
}

static void Benchmark(benchmark::State &state) {
  Solution::Solution solution;

  malloc_trim(0);
  for(auto _ : state) {
    state.PauseTiming();
    std::string randString = randomString(state.range(0), 5);
    state.ResumeTiming();
    solution.maxConsecutiveAnswers(randString, state.range(1));
  }
}

BENCHMARK(Benchmark)->ArgsProduct({{20,40,60},{3,5,10,20},{3,5,10,20}})->Complexity();
