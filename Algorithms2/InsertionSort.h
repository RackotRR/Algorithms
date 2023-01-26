#pragma once
#include <span>

template<typename T>
void insertionSort(std::span<T> arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        size_t j = i;
        while (j != 0 && arr[j - 1] > arr[j]) {
            std::swap(arr[j - 1], arr[j]);
            --j;
        }
    }
}