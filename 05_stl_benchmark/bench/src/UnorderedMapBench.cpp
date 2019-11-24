#include "Small.h"
#include "BenchIncludes.h"
#include <unordered_map>
/*
empty, size, max_size,
clear, insert, erase, swap,
at, operator[], count, find, equal_range,
rehash, reserve*/

void emptyUnorderedMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> map;
    for( auto _ : state){
        map.empty();
    }
    state.SetComplexityN(N);
}

BENCHMARK(emptyUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void sizeUnorderedMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> map;
    for( auto _ : state){
        map.size();
    }
    state.SetComplexityN(N);
}

BENCHMARK(sizeUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void maxSizeUnorderedMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> map;
    for( auto _ : state){
        map.max_size();
    }
    state.SetComplexityN(N);
}

BENCHMARK(maxSizeUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void clearUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> map;
    for( auto i=0; i<N; i++)
        map.insert({i,x});
    for( auto _ : state){
        map.clear();
    }
    state.SetComplexityN(N);
}

BENCHMARK(clearUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void insertUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> map;

    for( auto _ : state){
        for( auto i=0; i<N; i++)
            map.insert({i,x});
    }
    state.SetComplexityN(N);
}

BENCHMARK(insertUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void eraseUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> map;

    for( auto _ : state){
        state.PauseTiming();
        for(auto i=0; i<N; i++)
            map.insert({i,x});
        state.ResumeTiming();
        map.erase(rand()%N);
    }
    state.SetComplexityN(N);
}

BENCHMARK(eraseUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void swapUnorderedMap(State& state) {
    Small x,y;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> map;
    std::unordered_map<int, Small> map1;
    for(auto i=0; i<N; i++) {
        map.insert({i, x});
        map1.insert({i, y});
    }
    for( auto _ : state){
        map.swap(map1);
    }
    state.SetComplexityN(N);
}

BENCHMARK(swapUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void atUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> map;
    for(auto i=0; i<N; i++)
        map.insert({i, x});

    for( auto _ : state){
        map.at(rand()%N);
    }
    state.SetComplexityN(N);
}

BENCHMARK(atUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void operatorUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> map;

    for( auto _ : state){
        for(auto i=0; i<N; i++)
            map[i]=x;
    }
    state.SetComplexityN(N);
}

BENCHMARK(operatorUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void countUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> map;

    for(auto i=0; i<N; i++)
        map.insert({i,x});

    for( auto _ : state){
        map.count(rand()%N);
    }
    state.SetComplexityN(N);
}

BENCHMARK(countUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void findUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> map;

    for(auto i=0; i<N; i++)
        map.insert({i,x});

    for( auto _ : state){
        map.find(rand()%N);
    }
    state.SetComplexityN(N);
}

BENCHMARK(findUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void equalRangeUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<int, Small> map;

    for(auto i=0; i<N; i++)
        map.insert({rand()%N,x});

    for( auto _ : state){
        map.equal_range(rand()%N);
    }
    state.SetComplexityN(N);
}

BENCHMARK(equalRangeUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void rehashUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    for( auto _ : state){
        state.PauseTiming();
             std::unordered_map<int, Small> map;
        state.ResumeTiming();

        map.rehash(N);

        state.PauseTiming();
             for(auto i=0; i<N; i++)
                 map.insert({i,x});
        state.ResumeTiming();
    }
    state.SetComplexityN(N);
}

BENCHMARK(rehashUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void reserveUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    for( auto _ : state){
        state.PauseTiming();
        std::unordered_map<int, Small> map;
        state.ResumeTiming();

        map.reserve(N);

        state.PauseTiming();
        for(auto i=0; i<N; i++)
            map.insert({i,x});
        state.ResumeTiming();
    }
    state.SetComplexityN(N);
}

BENCHMARK(reserveUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
