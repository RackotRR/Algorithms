#pragma once
#include <span>

template<typename T>
void merge(T* arr, size_t left, size_t center, size_t right) {
    size_t leftSize = center - left;
    size_t rightSize = right - center;
    
    auto leftArray = new T[leftSize];
    auto rightArray = new T[rightSize];
    std::memcpy(leftArray, &arr[left], leftSize * sizeof(T));
    std::memcpy(rightArray, &arr[center], rightSize * sizeof(T));

    size_t leftIdx = 0;
    size_t rightIdx = 0; 
    size_t mergedIdx = left;

    // Merge the temp arrays back into array[left..right]
    while (leftIdx < leftSize
        && rightIdx < rightSize) 
    {
        if (leftArray[leftIdx] <= rightArray[rightIdx]) {
            arr[mergedIdx] = leftArray[leftIdx];
            leftIdx++;
        }
        else {
            arr[mergedIdx] = rightArray[rightIdx];
            rightIdx++;
        }
        mergedIdx++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (leftIdx < leftSize) {
        arr[mergedIdx] = leftArray[leftIdx];
        leftIdx++;
        mergedIdx++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (rightIdx < rightSize) {
        arr[mergedIdx] = rightArray[rightIdx];
        rightIdx++;
        mergedIdx++;
    }
    
    delete[] leftArray;
    delete[] rightArray;
}

template<typename T>
void mergeSort(T* arr, size_t left, size_t right) {
    if (right - left < 2) {
        return;
    }

    size_t center = left + (right - left) / 2;
    mergeSort(arr, left, center);
    mergeSort(arr, center, right);
    merge(arr, left, center, right);
}

// neumann sort
template<typename T>
void mergeSort(std::span<T> arr) {
    mergeSort(arr.data(), 0, arr.size());
}