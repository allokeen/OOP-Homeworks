#include "Medium.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash

void mediumLessThanTime(State& state) {

    Medium medium{};
    for (auto _ : state) {

        auto result = (medium < medium);
        DoNotOptimize(result);
    }
}

BENCHMARK( mediumLessThanTime );

void mediumEqualityOperatorTime(State& state) {

    Medium medium{};
    for (auto _ : state) {

        auto result = (medium == medium);
        DoNotOptimize(result);
    }
}

BENCHMARK( mediumEqualityOperatorTime );

void mediumHashFunctionTime(State& state) {

    Medium medium{};
    for (auto _ : state) {
        auto result = std::hash<Medium>()(medium);
    }
}

BENCHMARK( mediumHashFunctionTime );
