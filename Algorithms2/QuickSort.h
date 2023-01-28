#pragma once
#include <span>

template<typename T>
size_t partition(T* arr, size_t n) {
	T pivot = arr[0];
	size_t i = n;
	size_t j = 0;

	while (true) {
		while (arr[--i] > pivot);
		while (arr[++j] < pivot);
		if (i <= j) {
			break;
		}
		std::swap(arr[i], arr[j]);
	}

	std::swap(arr[i], arr[0]);
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
	quickSort(arr.data(), arr.size());
}