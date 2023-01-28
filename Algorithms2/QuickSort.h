#pragma once
#include <span>

template<typename T>
size_t partition(T* arr, size_t n) {
	T pivot = arr[0];
	size_t i = n;
	size_t j = 0;

	while (true) {
		while (i != 1 && arr[--i] > pivot);
		while (j != n - 1 && arr[++j] < pivot);
		if (i <= j) {
			break;
		}
		if (arr[i] < arr[j]) {
			std::swap(arr[i], arr[j]);
		}
	}

	if (arr[i] < arr[0]) {
		std::swap(arr[i], arr[0]);
	}
	return i;
}

template<typename T>
void quickSort(T* arr, size_t n) {
	if (n > 1) {
		size_t j = partition(arr, n);
		quickSort(arr, j);
		quickSort(arr + j + 1, n - j - 1);
	}
}

template<typename T>
void quickSort(std::span<T> arr) {
	if (arr.size() > 1) {
		quickSort(arr.data(), arr.size());
	}
}