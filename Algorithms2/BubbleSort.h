#pragma once
#include <span>

template<typename T>
void bubbleSort(std::span<T> arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 1; j < arr.size() - i; ++j) {
            if (arr[j - 1] > arr[j]) {
                std::swap(arr[j - 1], arr[j]);
            }
        }
    }
}

template<typename T>
void bubbleSort_optimized(std::span<T> arr) {
    bool swapped = false;
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 1; j < arr.size() - i; ++j) {
            if (arr[j - 1] > arr[j]) {
                std::swap(arr[j - 1], arr[j]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
        swapped = false;
    }
}