#include "BenchIncludes.h"
//-----------------------------

void atSmallMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small,int> map{};
    Small x;

    for(auto i=0; i<size; i++)
    {
        x.randomize();
       auto j = rand()%size;
       map.insert({{x},j});
    }

    for( auto _ : state){
        map.at({x});
    }
    state.SetComplexityN(N);
}

BENCHMARK(atSmallMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void operatorSmallMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small,int> map{};
    Small x;
    auto z=rand()%size;

    for(auto i=0; i<size; i++)
    {
        x.randomize();
        auto j = rand()%size;
        map.insert({{x},j});
    }

    for( auto _ : state){
        x.randomize();
        map[x]= z;
    }
    state.SetComplexityN(N);

}
BENCHMARK(operatorSmallMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void emptySmallMap(State& state) {
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small,int> map{};
    Small x;

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
BENCHMARK(emptySmallMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void sizeSmallMap(State& state) {
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small,int> map{};
    Small x;

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
BENCHMARK(sizeSmallMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void maxSizeSmallMap(State& state) {
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small,int> map{};

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
BENCHMARK(maxSizeSmallMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void clearSmallMap(State& state) {
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Small x;

    for( auto _ : state){
        state.PauseTiming();
        std::map<Small,int> map{};

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

BENCHMARK(clearSmallMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void insertSmallMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small,int> map{};
    Small x;
    auto z= rand()%size;

    for(auto i=0; i<size; i++)
    {
        x.randomize();
        auto y= rand()%size;
        map.insert({x,y});
    }

    for( auto _ : state){
        x.randomize();
        map.insert({x,z});
    }
    state.SetComplexityN(N);
}

BENCHMARK(insertSmallMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void eraseSmallMap(State& state) {
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small,int> map{};
    Small x;
    auto y= rand()%size;

    for(auto i=0; i<size; i++)
    {
        x.randomize();
        auto y= rand()%size;
        map.insert({x,y});
    }

    for( auto _ : state){
        state.PauseTiming();
        x.randomize();
        map.insert({x,y});
        state.ResumeTiming();
        map.erase(x);
    }
    state.SetComplexityN(N);
}


BENCHMARK(eraseSmallMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void swapSmallMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small,int> map{};
    std::map<Small,int> map1{};
    Small x;

    for(auto i=0; i<size; i++)
    {
        auto j=rand()%size;
        x.randomize();
        map.insert({x,j});
        x.randomize();
        map1.insert({x,j});
    }

    for( auto _ : state){
        map.swap(map1);
    }
    state.SetComplexityN(N);
}

BENCHMARK(swapSmallMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void countSmallMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small,int> map{};
    Small x;

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

BENCHMARK(countSmallMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void findSmallMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small,int> map{};
    Small x;

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

BENCHMARK(findSmallMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void equalRangeSmallMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small,int> map{};
    Small x;

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

BENCHMARK(equalRangeSmallMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void lowerBoundSmallMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small,int> map{};
    Small x;
    for(auto i=0; i<size; i++)
    {
        x.randomize();
        auto y= rand()%size;
        map.insert({x,y});
    }

    for( auto _ : state){
        x.randomize();
        map.lower_bound(x);
    }
    state.SetComplexityN(N);
}

BENCHMARK(lowerBoundSmallMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------

void upperBoundSmallMap(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small,int> map{};
    Small x;
    for(auto i=0; i<size; i++)
    {
        x.randomize();
        auto y= rand()%size;
        map.insert({x,y});
    }

    for( auto _ : state){
        x.randomize();
        map.upper_bound(x);
    }
    state.SetComplexityN(N);
}

BENCHMARK(upperBoundSmallMap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
//-----------------------------
