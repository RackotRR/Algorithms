#pragma once
#include <span>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <concepts>

template<typename T, size_t base>
    requires std::unsigned_integral<T>
void countingSortSubroutine(std::span<T> arr, std::vector<T>& buffer, size_t place) {
    std::array<size_t, base> counts{ 0 };

    for (auto& item : arr) {
        counts[(item / place) % base]++;
    }
    for (size_t i = 1; i < base; ++i) {
        counts[i] += counts[i - 1];
    }

    for (size_t i = arr.size(); i > 0; --i) {
        auto j = i - 1;
        auto idx = (arr[j] / place) % base;
        buffer[counts[idx] - 1] = arr[j];
        counts[idx]--;
    }
    std::copy(std::begin(buffer), std::end(buffer), std::begin(arr));
}

template<typename T>
    requires std::unsigned_integral<T>
void radixSort(std::span<T> arr) {
    static_assert(std::numeric_limits<T>::is_integer);
    if (arr.empty()) return;
    
    std::vector<T> buffer(arr.size());

    constexpr size_t base = 256;
    auto max = *std::max_element(std::begin(arr), std::end(arr));
    for (size_t place = 1; max / place != 0; place *= base) {
        countingSortSubroutine<T, base>(arr, buffer, place);
    }
}