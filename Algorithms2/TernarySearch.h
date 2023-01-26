#pragma once
#include <span>

template<typename T>
T* ternarySearch(const T& x, std::span<T> arr) {
    size_t left = 0;
    size_t right = arr.size() - 1;

    while (right >= left) {
        size_t mid_left = left + (right - left) / 3;
        size_t mid_right = left + (right - left) / 3 * 2;

        if (arr[mid_left] > x) {
            if (mid_left == 0) {
                return nullptr;
            }
            right = mid_left - 1;
        }
        else if (arr[mid_right] < x) {
            if (mid_right == arr.size() - 1) {
                return nullptr;
            }
            left = mid_right + 1;
        }
        else if (arr[mid_left] == x) {
            return &arr[mid_left];
        }
        else if (arr[mid_right] == x) {
            return &arr[mid_right];
        }
        else {
            left = mid_left + 1;
            right = mid_right - 1;
        }
    }

    return nullptr;
}