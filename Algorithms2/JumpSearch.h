#pragma once
#include <span>
#include <cmath>

template<typename T>
T* jumpSearch(const T& x, std::span<T> arr) {
    size_t jump = std::sqrt(arr.size());
    size_t i = 0;
    
    while (i < arr.size() && x > arr[i]) {
        i += jump;
    }
    
    size_t n = std::min(i + jump, arr.size());
    i = i < jump ? 0 : i - jump;
    for (; i < n; ++i) {
        if (arr[i] == x) {
            return &arr[i];
        }
    }

    return nullptr;
}