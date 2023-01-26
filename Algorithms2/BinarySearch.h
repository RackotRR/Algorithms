#pragma once
#include <span>

template<typename T>
T* binarySearch_recursive(const T& x, T* arr, size_t size) {
	size_t centerI = size / 2;
	const T& centerValue = arr[centerI];

	if (centerValue == x) {
		return arr + centerI;
	}
	else if (size == 1) {
		return nullptr;
	}
	
	if (centerValue > x) { // left side
		return binarySearch(x, arr, centerI);
	}
	else { // right side
		return binarySearch(x, arr + centerI, size);
	}
}

template<typename T>
T* binarySearch_iterative(const T& x, T* arr, size_t size) {
	size_t left = 0;
	size_t right = size;
	size_t center;

	while (right >= left) {
		center = (left + right) / 2;
		if (arr[center] < x) {
			left = center + 1;
		}
		else if (arr[center] > x) {
			right = center - 1;
		}
		else {
			return &arr[center];
		}
	}

	return nullptr;
}

template<typename T>
T* binarySearch(const T& x, std::span<T> arr) {
	if (x > *arr.rbegin() ||
		x < *arr.begin()) {
		return nullptr;
	}
	else {
		return binarySearch_iterative(x, arr.data(), arr.size());
	}
}

