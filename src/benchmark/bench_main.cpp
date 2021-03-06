#include <benchmark/benchmark.h>
#include "calc_if.h"

static void BM_StringCreation(benchmark::State &state)
{
    for (auto _ : state)
    {
        std::string empty_string;
    }
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State &state)
{
    std::string x = "hello";
    for (auto _ : state)
    {
        std::string copy(x);
    }
}
BENCHMARK(BM_StringCopy);

static void BM_Calc_Add(benchmark::State &state)
{
    for (auto _ : state)
    {
        for (int i = 0; i < state.range(0); ++i)
        {
            Add(i, i);
        }
    }
}
BENCHMARK(BM_Calc_Add)->Range(1, 1 << 16);

BENCHMARK_MAIN();