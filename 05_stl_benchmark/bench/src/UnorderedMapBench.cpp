#include "BenchIncludes.h"
/*
empty, size, max_size,
clear, insert, erase, swap,
at, operator[], count, find, equal_range,
rehash, reserve*/

void emptyUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, int> map;

    for(auto i=0; i<size; i++)
    {
        x.randomize();
        auto y= rand()%size;
        map.insert({x,y});
    }

    for( auto _ : state){
        map.empty();
    }
    state.SetComplexityN(N);
}

BENCHMARK(emptyUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void sizeUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, int> map;

    for(auto i=0; i<size; i++)
    {
        x.randomize();
        auto y= rand()%size;
        map.insert({x,y});
    }

    for( auto _ : state){
        map.size();
    }
    state.SetComplexityN(N);
}

BENCHMARK(sizeUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void maxSizeUnorderedMap(State& state) {

    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, int> map;

    for(auto i=0; i<size; i++)
    {
        x.randomize();
        auto y= rand()%size;
        map.insert({x,y});
    }

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

    for( auto _ : state){
        state.PauseTiming();
        std::unordered_map<Small, int> map;
        for(auto i=0; i<size; i++)
        {
            x.randomize();
            auto y= rand()%size;
            map.insert({x,y});
        }
        state.ResumeTiming();
        map.clear();
    }
    state.SetComplexityN(N);
}

BENCHMARK(clearUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void insertUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, int> map;
    auto z= rand()%size;

    for(auto i=0; i<size; i++)
    {
        x.randomize();
        auto y= rand()%size;
        map.insert({x,y});
    }

    for( auto _ : state){
        map.insert({x,z});
    }
    state.SetComplexityN(N);
}

BENCHMARK(insertUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void eraseUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, int> map;
    auto z= rand()%size;

    for(auto i=0; i<size; i++)
    {
        x.randomize();
        auto y= rand()%size;
        map.insert({x,y});
    }

    for( auto _ : state){
        state.PauseTiming();
        x.randomize();
        map.insert({x,z});
        state.ResumeTiming();
        map.erase(x);
    }
    state.SetComplexityN(N);
}

BENCHMARK(eraseUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void swapUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, int> map;
    std::unordered_map<Small, int> map1;

    for(auto i=0; i<size; i++)
    {
        auto z= rand()%size;
        x.randomize();
        map.insert({x,z});
        x.randomize();
        map1.insert({x,z});
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
    std::unordered_map<Small, int> map;

    for(auto i=0; i<size; i++)
    {
        x.randomize();
        auto y= rand()%size;
        map.insert({{x},y});
    }

    for( auto _ : state){
        map.at({x});
    }
    state.SetComplexityN(N);
}

BENCHMARK(atUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void operatorUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, int> map;
    auto z=rand()%size;

    for(auto i=0; i<size; i++)
    {
        x.randomize();
        auto y= rand()%size;
        map.insert({x,y});
    }

    for( auto _ : state){
        x.randomize();
        map[x]= z;
    }
    state.SetComplexityN(N);
}

BENCHMARK(operatorUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void countUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, int> map;

    for(auto i=0; i<size; i++)
    {
        x.randomize();
        auto y= rand()%size;
        map.insert({x,y});
    }

    for( auto _ : state){
        x.randomize();
        map.count(x);
    }
    state.SetComplexityN(N);
}

BENCHMARK(countUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void findUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, int> map;

    for(auto i=0; i<size; i++)
    {
        x.randomize();
        auto y= rand()%size;
        map.insert({x,y});
    }

    for( auto _ : state){
        x.randomize();
        map.find(x);
    }
    state.SetComplexityN(N);
}

BENCHMARK(findUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void equalRangeUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_map<Small, int> map;

    for(auto i=0; i<size; i++)
    {
        x.randomize();
        auto y= rand()%size;
        map.insert({x,y});
    }

    for( auto _ : state){
        x.randomize();
        map.equal_range(x);
    }
    state.SetComplexityN(N);
}

BENCHMARK(equalRangeUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void rehashUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    for( auto _ : state){
        state.PauseTiming();
            std::unordered_map<Small, int> map;
        state.ResumeTiming();

        map.rehash(size);

        state.PauseTiming();
        for(auto i=0; i<size; i++)
        {
            x.randomize();
            auto y= rand()%size;
            map.insert({x,y});
        }
        state.ResumeTiming();
    }
    state.SetComplexityN(N);
}

BENCHMARK(rehashUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void reserveUnorderedMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    for( auto _ : state){
        state.PauseTiming();
        std::unordered_map<Small, int> map;
        state.ResumeTiming();

        map.reserve(size);

        state.PauseTiming();
        for(auto i=0; i<size; i++)
        {
            x.randomize();
            auto y= rand()%size;
            map.insert({x,y});
        }
        state.ResumeTiming();
    }
    state.SetComplexityN(N);
}

BENCHMARK(reserveUnorderedMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
