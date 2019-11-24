#include "Small.h"
#include "BenchIncludes.h"
#include <map>
//-----------------------------

void atMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<int, Small> map{};
    Small x;
    for(auto i=0; i<N; i++)
         map.insert({i,x});

    for( auto _ : state){
        map.at(rand()%N);
    }
    state.SetComplexityN(N);
}

BENCHMARK(atMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void operatorMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<int, Small> map{};
    Small x;

    for( auto _ : state){
        for(auto i=0; i<N; i++)
            map[i]= x;
    }
    state.SetComplexityN(N);

}
BENCHMARK(operatorMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void emptyMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<int, Small> map{};

    for( auto _ : state){
        map.empty();
    }
    state.SetComplexityN(N);

}
BENCHMARK(emptyMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void sizeMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<int, Small> map{};
    for(auto i=0; i<N; i++)
        map.insert({i,x});

    for( auto _ : state){
        map.size();
    }
    state.SetComplexityN(N);

}
BENCHMARK(sizeMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void maxSizeMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<int, Small> map{};
    for(auto i=0; i<N; i++)
        map.insert({i,x});

    for( auto _ : state){
        map.max_size();
    }
    state.SetComplexityN(N);

}
BENCHMARK(maxSizeMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void clearMap(State& state) {
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<int, Small> map{};
    Small x;
    for(auto i=0; i<N; i++)
        map.insert({i,x});

    for( auto _ : state){
        map.clear();
    }
    state.SetComplexityN(N);
}

BENCHMARK(clearMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void insertMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<int, Small> map{};
    Small x;
    for( auto _ : state){
        for(auto i=0; i<N; i++)
            map.insert({i,x});
    }
    state.SetComplexityN(N);
}

BENCHMARK(insertMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void eraseMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<int, Small> map{};
    Small x;
    for( auto _ : state){
        state.PauseTiming();
        for(auto i=0; i<N; i++)
            map.insert({i,x});
        state.ResumeTiming();
        map.erase(rand()%N);
    }
    state.SetComplexityN(N);
}

BENCHMARK(eraseMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void swapMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<int, Small> map{};
    std::map<int, Small> map1{};
    Small x;
    Small y;
    for(auto i=0; i<N; i++)
    {
        map.insert({i,x});
        map1.insert({i,y});
    }
    for( auto _ : state){
        map.swap(map1);
    }
    state.SetComplexityN(N);
}

BENCHMARK(swapMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void countMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<int, Small> map{};
    Small x;

    for(auto i=0; i<N; i++)
        map.insert({i,x});

    for( auto _ : state){
        map.count(rand()%N);
    }
    state.SetComplexityN(N);
}

BENCHMARK(countMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void findMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<int, Small> map{};
    Small x;

    for(auto i=0; i<N; i++)
        map.insert({i,x});

    for( auto _ : state){
        map.find(rand()%N);
    }
    state.SetComplexityN(N);
}

BENCHMARK(findMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void equalRangeMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<int, Small> map{};
    Small x;

    for(auto i=0; i<N; i++)
        map.insert({i,x});

    for( auto _ : state){
        map.equal_range(rand()%N);
    }
    state.SetComplexityN(N);
}

BENCHMARK(equalRangeMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void lowerBoundMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<int, Small> map{};
    Small x;
    for(auto i=0; i<N; i++)
        map.insert({i,x});

    for( auto _ : state){
        map.lower_bound(rand()%N);
    }
    state.SetComplexityN(N);
}

BENCHMARK(lowerBoundMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void upperBoundMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<int, Small> map{};
    Small x;
    for(auto i=0; i<N; i++)
        map.insert({i,x});

    for( auto _ : state){
        map.upper_bound(rand()%N);
    }
    state.SetComplexityN(N);
}

BENCHMARK(upperBoundMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------
