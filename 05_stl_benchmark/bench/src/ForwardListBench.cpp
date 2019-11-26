#include "BenchIncludes.h"


void frontForwardList(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::forward_list<Small> forwardList(size);

    for( auto _ : state){
        auto result = forwardList.front();
    }
    state.SetComplexityN(N);
}
BENCHMARK(frontForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void emptyForwardList(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::forward_list<Small> forwardList(size);

    for( auto _ : state){
        forwardList.empty();
    }
    state.SetComplexityN(N);
}

BENCHMARK(emptyForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void maxSizeForwardList(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::forward_list<Small> forwardList(size);

    for( auto _ : state){

        forwardList.max_size();
    }
    state.SetComplexityN(N);
}

BENCHMARK(maxSizeForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


void clearForwardList(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for( auto _ : state){
        state.PauseTiming();
        std::forward_list<Small> forwardList(size);
        state.ResumeTiming();

        forwardList.clear();
    }
    state.SetComplexityN(N);
}

BENCHMARK(clearForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


void insertAfterForwardList(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::forward_list<Small> forwardList(size);
    auto start = forwardList.before_begin();
    Small x;
    for( auto _ : state){
        forwardList.insert_after( start,x );

        state.PauseTiming();
        forwardList.pop_front();
        state.ResumeTiming();

    }
    state.SetComplexityN(N);
}

BENCHMARK(insertAfterForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void eraseAfterForwardList(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::forward_list<Small> forwardList(size);
    Small x;
    auto start = forwardList.before_begin();
    for( auto _ : state){
        state.PauseTiming();
        forwardList.insert_after( start,x );
        state.ResumeTiming();
        forwardList.erase_after( start );
    }
    state.SetComplexityN(N);
}

BENCHMARK(eraseAfterForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void pushFrontForwardList(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::forward_list<Small> forwardList(size);
    Small x;
    for( auto _ : state){
        forwardList.push_front(x);
        state.PauseTiming();
        forwardList.pop_front();
        state.ResumeTiming();
    }
    state.SetComplexityN(N);
}

BENCHMARK(pushFrontForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void popFrontForwardList(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::forward_list<Small> forwardList(size);
    Small x;
    for( auto _ : state){
        state.PauseTiming();
        forwardList.push_front(x);
        state.ResumeTiming();
        forwardList.pop_front();
    }
    state.SetComplexityN(N);
}

BENCHMARK(popFrontForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void resizeForwardList(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::forward_list<Small> forwardList(size);

    for( auto _ : state) {
        forwardList.resize(rand()%N);
    }
    state.SetComplexityN(N);
}

BENCHMARK(resizeForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void swapForwardList(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::forward_list<Small> forwardList(size);
    std::forward_list<Small> forwardList2(size);

    for( auto _ : state) {
        forwardList.swap(forwardList2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(swapForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void mergeForwardList(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for( auto _ : state) {

        state.PauseTiming();
        std::forward_list<Small> forwardList(size);
        std::forward_list<Small> forwardList2(size);
        forwardList.sort();
        forwardList2.sort();
        state.ResumeTiming();
        forwardList.merge(forwardList2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(mergeForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void spliceAfterForwardList(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for( auto _ : state) {
        state.PauseTiming();
        std::forward_list<Small> forwardList(size);
        std::forward_list<Small> forwardList2(size);
        auto begin = forwardList.before_begin();
        state.ResumeTiming();
        forwardList.splice_after(begin, forwardList2);
    }
    state.SetComplexityN(N);
}

BENCHMARK(spliceAfterForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void removeForwardList(State& state) {
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::forward_list<Small> forwardList(size);
    Small x;

    for( auto _ : state) {
        state.PauseTiming();
        for(auto i=0; i<N; i++)
            forwardList.push_front(x);
        state.ResumeTiming();
        forwardList.remove(x);
    }
    state.SetComplexityN(N);
}

BENCHMARK(removeForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void removeIfForwardList(State& state) {
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::forward_list<Small> forwardList(size);
    Small x;

    for( auto _ : state) {
        state.PauseTiming();
        for(auto i=0; i<N; i++)
            forwardList.push_front(x);
        state.ResumeTiming();
       forwardList.remove_if([x](Small y){return y == x;});
    }
    state.SetComplexityN(N);
}

BENCHMARK(removeIfForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void reverseForwardList(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::forward_list<Small> forwardList(size);

    for( auto _ : state) {
        forwardList.reverse();
    }
    state.SetComplexityN(N);
}

BENCHMARK(reverseForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void uniqueForwardList(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::forward_list<Small> forwardList(size);
    Small x;

    for( auto _ : state) {
        state.PauseTiming();
        for(auto i=0; i<N; i++)
            forwardList.push_front(x);
        state.ResumeTiming();
        forwardList.unique();
    }
    state.SetComplexityN(N);
}
BENCHMARK(uniqueForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void sortForwardList(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Small x;
    for( auto _ : state) {
        state.PauseTiming();
        std::forward_list<Small> forwardList(size);
        for(auto i=0; i<N; i++)
            forwardList.push_front(x);
        state.ResumeTiming();
        forwardList.sort();
    }
    state.SetComplexityN(N);
}
BENCHMARK(sortForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();