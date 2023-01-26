#pragma once
#include <span>

inline float lerp(float a, float b, float t) {
    return a + (b - a) * t;
}

inline float unlerp(float a, float b, float x) {
    return (x - a) / (b - a);
}

template<typename T>
T* interpolationSearch(const T& x, std::span<T> arr) {
    if (arr.empty()) {
        return nullptr;
    }

    size_t left = 0;
    size_t right = arr.size() - 1;

    while (right >= left &&
        x >= arr[left] && 
        x <= arr[right]) 
    {
        const T& first = arr[left];
        const T& last = arr[right];

        float k = unlerp(first, last, x);
        size_t i = lerp(left, right, k);

        if (arr[i] > x) {
            right = i - 1;
        }
        else if (arr[i] < x) {
            left = i + 1;
        }
        else if (arr[i] == x) {
            return &arr[i];
        }
    }

    return nullptr;
}
