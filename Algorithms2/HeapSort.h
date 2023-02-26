#pragma once
#include <algorithm>
#include <functional>
#include <span>

template<typename T, typename CmpT = std::less<T>>
void addElementAtHeap(std::span<T> arr, size_t idx) {
    CmpT cmp{};
    size_t current_idx = idx;

    while (true) {
        size_t left_child_idx = current_idx * 2 + 1;
        size_t right_child_idx = left_child_idx + 1;

        bool has_left_child = left_child_idx < arr.size();
        bool has_right_child = right_child_idx < arr.size();
        int children = has_left_child + has_right_child;

        if (children == 0) {
            break;
        }
        else {
            size_t child_to_compare = left_child_idx;
            if (has_right_child && cmp(arr[left_child_idx], arr[right_child_idx])) {
                child_to_compare = right_child_idx;
            }

            if (cmp(arr[current_idx], arr[child_to_compare])) {
                std::swap(arr[child_to_compare], arr[current_idx]);
                current_idx = child_to_compare;
            }
            else {
                break;
            }
        }
    }
}

template<typename T>
void heapify(std::span<T> arr) {
    size_t N = arr.size();
    if (N <= 1) {
        return;
    }

    size_t heap_from = N / 2;
    do {
        addElementAtHeap(arr, heap_from--);
    } while (heap_from != 0);
    addElementAtHeap(arr, heap_from);
}

template<typename T>
void heapSort(std::span<T> arr) {
    heapify(arr);

    size_t N = arr.size();
    while (N != 1) {
        std::swap(arr[0], arr[--N]);
        addElementAtHeap(std::span<T>(arr.data(), N), 0);
    }
}
