#include "Small.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash

void smallLessThanTime(State& state) {

    Small small{};
    for (auto _ : state) {

        auto result = (small < small);
        DoNotOptimize(result);
    }
}

BENCHMARK( smallLessThanTime );

void smallEqualityOperatorTime(State& state) {

    Small small{};
    for (auto _ : state) {

        auto result = (small == small);
        DoNotOptimize(result);
    }
}

BENCHMARK( smallEqualityOperatorTime );

void smallHashFunctionTime(State& state) {

    Small small{};
    for (auto _ : state) {
        auto result = std::hash<Small>()(small);
        DoNotOptimize(result);
    }
}

BENCHMARK( smallHashFunctionTime );
