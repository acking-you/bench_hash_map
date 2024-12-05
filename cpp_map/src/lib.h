#pragma once
#include <iostream>
#include <chrono>
#include <ranges>

template<typename T>
concept MyHashMap = requires(T map, int32_t i32_value)
{
    { T::from_i32_range(i32_value, i32_value) } -> std::same_as<T>;
    { map.get(i32_value) } -> std::same_as<std::optional<int32_t> >;
};

constexpr int32_t RANGE_START = 0;
constexpr int32_t RANGE_END = 1000000;

template<MyHashMap T>
void bench_hashmap_get() {
    T map = T::from_i32_range(RANGE_START, RANGE_END);

    for (int t = 0; t < 100; ++t) {
        auto start = std::chrono::high_resolution_clock::now();

        int32_t sum = 0;
        for (int i: std::ranges::iota_view(RANGE_START, RANGE_END)) {
            auto &&value = map.get(i);
            sum += *value;
        }

        if (t > 95) {
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(
                std::chrono::high_resolution_clock::now() - start).count();
            float_t ms = static_cast<float_t>(elapsed) / 1000000.0;
            std::cout << std::format("test round {}, sum: {}, elapsed: {:.2f} ms\n", t, sum, ms);
        }
    }
}
