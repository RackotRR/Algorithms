#pragma once
#include <span>
#include <vector>
#include <algorithm>
#include <limits>

template<typename T>
void countingSort(std::span<T> arr, T min, T max) {
    static_assert(std::numeric_limits<T>::is_integer);

    if (min >= max || arr.empty()) {
        return;
    }
    auto range = max - min + 1;
    std::vector<size_t> counts(range);

    for (auto& item : arr) {
        counts[item - min]++;
    }
    for (T i = 1; i < range; ++i) {
        counts[i] += counts[i - 1];
    }

    size_t count = 0;
    for (T i = 0; i < range; ++i) {
        for (size_t j = count; j < counts[i]; ++j) {
            arr[j] = i + min;
        }
        count = counts[i];
    }
}

template<typename T>
void countingSort(std::span<T> arr) {
    auto [pMin, pMax] = std::minmax_element(std::begin(arr), std::end(arr));
    countingSort(arr, *pMin, *pMax);
}