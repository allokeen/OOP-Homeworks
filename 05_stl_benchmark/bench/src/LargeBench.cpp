#include "Large.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash

void largeLessThanTime(State& state) {

    Large large{};
    for (auto _ : state) {
        auto result = (large < large);
        DoNotOptimize(result);
    }
}
BENCHMARK( largeLessThanTime );

void largeEqualityOperatorTime(State& state) {

    Large large{};
    for (auto _ : state) {
        auto result = (large == large);
        DoNotOptimize(result);
    }
}
BENCHMARK( largeEqualityOperatorTime );

void largeHashFunctionTime(State& state) {

    Large large{};
    for (auto _ : state) {
        auto result = std::hash<Large>()(large);
    }
}
BENCHMARK( largeHashFunctionTime );