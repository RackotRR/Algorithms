#pragma once
#include <span>

template<typename T>
void selectionSort(std::span<T> arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (i != min_idx) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}