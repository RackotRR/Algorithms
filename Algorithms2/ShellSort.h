#pragma once
#include <span>

template<typename T>
void insertionSortWithStep(std::span<T> arr, size_t step) {
    for (size_t i = step; i < arr.size(); ++i) {
        size_t j = i;
        while (j >= step && arr[j - step] > arr[j]) {
            std::swap(arr[j - step], arr[j]);
            j -= step;
        }
    }
}

template<typename T>
void shellSort(std::span<T> arr) {
    // knuth step, 1973
    size_t stepK = 3;
    size_t maxStep = arr.size() / stepK;
    size_t step = 1;
    while (step < maxStep) {
        step = step * stepK + 1;
    }

    while (step >= 1) {
        insertionSortWithStep(arr, step);
        step /= stepK;
    }
}