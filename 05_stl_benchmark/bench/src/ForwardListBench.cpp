#include "Small.h"
#include "BenchIncludes.h"
#include <forward_list>

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
    Small x;
    for( auto _ : state){

        state.PauseTiming();
        for(auto i=0; i<N; i++)
            forwardList.push_front(x);
        state.ResumeTiming();

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


void clearForwardList(State& state) { //?????????????????????????????????????????????????????

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

    for( auto _ : state){
        state.PauseTiming();
        std::forward_list<Small> forwardList(size);
        Small x;
        auto start = forwardList.begin();
        state.ResumeTiming();
        forwardList.insert_after( start,x );
    }
    state.SetComplexityN(N);
}

BENCHMARK(insertAfterForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void eraseAfterForwardList(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for( auto _ : state){
        state.PauseTiming();
        std::forward_list<Small> forwardList(size);
        Small x;
        forwardList.insert_after( forwardList.begin(),x );
        auto element = forwardList.before_begin();
        state.ResumeTiming();

        forwardList.erase_after( element );
    }
    state.SetComplexityN(N);
}

BENCHMARK(eraseAfterForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void pushFrontAfterForwardList(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for( auto _ : state){
        state.PauseTiming();
        std::forward_list<Small> forwardList(size);
        Small x;
        state.ResumeTiming();

        forwardList.push_front(x);
    }
    state.SetComplexityN(N);
}

BENCHMARK(pushFrontAfterForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void popFrontForwardList(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for( auto _ : state){
        state.PauseTiming();
        std::forward_list<Small> forwardList(size);
        Small x;
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
        state.PauseTiming();
        auto x= rand();
        state.ResumeTiming();

        forwardList.resize(x);
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

void removeForwardList(State& state) { //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::forward_list<Small> forwardList(size);

    for( auto _ : state) {
        state.PauseTiming();
        for( auto i=0; i<N; i++ )
        {
            forwardList.push_front(x);
        }
        state.ResumeTiming();
        forwardList.remove(x);  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    state.SetComplexityN(N);
}

BENCHMARK(removeForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void removeIfForwardList(State& state) { //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    Small x;
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::forward_list<Small> forwardList(size);

    for( auto _ : state) {
        state.PauseTiming();
        for( auto i=0; i<N; i++ )
        {
            forwardList.push_front(x);
        }
        state.ResumeTiming();
        //forwardList.remove_if(x);  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
        for( auto i=0; i<N; i++ )
        {
            forwardList.push_front(x);
        }
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
    std::forward_list<Small> forwardList(size);
    Small x;

    for( auto _ : state) {
        state.PauseTiming();
        for( auto i=0; i<N; i++ )
        {
            forwardList.push_front(x);
        }
        state.ResumeTiming();
        forwardList.sort();
    }
    state.SetComplexityN(N);
}
BENCHMARK(sortForwardList)->RangeMultiplier(2)->Range(1, 1024)->Complexity();