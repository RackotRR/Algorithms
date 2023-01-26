#pragma once
#include <span>

template<typename T>
T* linearSearch(const T& x, std::span<T> arr) {
    for (auto& item : arr) {
        if (item == x) {
            return &item;
        }
    }
    return nullptr;
}