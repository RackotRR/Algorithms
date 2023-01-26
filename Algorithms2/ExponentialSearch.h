#pragma once
#include <iostream>
#include "BinarySearch.h"

template<typename T>
T* exponentialSearch(const T& x, std::span<T> arr) {
    size_t i = 1;

    while (i < arr.size() &&
        x >= arr[i]) 
    {
        i *= 2;
    }

    auto ptr = arr.data() + i / 2;
    size_t size = std::min(i, arr.size()) - i / 2;
    return binarySearch(x, std::span(ptr, size));
}
