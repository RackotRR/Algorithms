#pragma once
#include <span>

template<typename T>
void partition3Way(T* arr, size_t n, size_t& leftPivot, size_t& rightPivot) {
	T pivot = arr[0];
	size_t i = n;
	size_t j = 0;

	size_t lp = 0; // pivots on left side
	size_t rp = n; // pivots on right side

	while (true) {
		while (arr[--i] > pivot);
		while (arr[++j] < pivot);
		if (i <= j) {
			break;
		}

		std::swap(arr[i], arr[j]);

		if (arr[i] == pivot) {
			std::swap(arr[i], arr[--rp]);
		}
		if (arr[j] == pivot) {
			std::swap(arr[j], arr[++lp]);
		}
	}

	size_t ip = i;
	rightPivot = ip + 1;
	for (size_t k = 0; k <= lp; ++k) {
		std::swap(arr[ip - k], arr[lp - k]);
	}
	for (size_t k = rp; k < n; ++k) {
		std::swap(arr[rightPivot++], arr[k]);
	}	
	leftPivot = ip - lp;
}

template<typename T>
void quickSort3Way(T* arr, size_t n) {
	if (n > 1) {
		size_t leftPivot;
		size_t rightPivot;
		partition3Way(arr, n, leftPivot, rightPivot);
		quickSort3Way(arr, leftPivot);
		quickSort3Way(arr + rightPivot, n - rightPivot);
	}
}

template<typename T>
void quickSort3Way(std::span<T> arr) {
	quickSort3Way(arr.data(), arr.size());
}