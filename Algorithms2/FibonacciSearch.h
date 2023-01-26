#pragma once
#include <span>

template<typename T>
T* fibonacciSearch(const T& x, std::span<T> arr) {
    size_t n = arr.size();
    size_t fib_m2 = 0;
    size_t fib_m1= 1;
    size_t fib = fib_m2 + fib_m1;

    while (fib < n) {
        fib_m2 = fib_m1;
        fib_m1 = fib;
        fib = fib_m2 + fib_m1;
    }
    
    size_t offset = -1;
    while (fib > 1) {
        size_t i = std::min<size_t>(offset + fib_m2, n - 1);
        
        if (arr[i] < x) {
            fib = fib_m1;
            fib_m1 = fib_m2;
            fib_m2 = fib - fib_m1;
            offset = i;
        }
        else if (arr[i] > x) {
            fib = fib_m2;
            fib_m1 = fib_m1 - fib_m2;
            fib_m2 = fib - fib_m1;
        }
        else {
            return &arr[i];
        }
    }

    if (arr[n - 1] == x) {
        return &arr[n - 1];
    }
    return nullptr;
}