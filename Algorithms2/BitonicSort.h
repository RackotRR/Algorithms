#pragma once
#include <span>
#include <stdexcept>

size_t countPasses(size_t size) {
    size_t passes = 0;
    while (size != 1) {
        if (size % 2 == 1) {
            throw std::runtime_error{ "array size must be of a power of 2 for bitonic sort" };
        }
        size /= 2;
        ++passes;
    }
    return passes;
}

template<typename T>
void bitonicSort(std::span<T> arr) {
    size_t passes = countPasses(arr.size());
    for (size_t pass = 0; pass < passes; ++pass) {
        size_t max_step_size = 1ull << pass;
        for (size_t step_size = max_step_size; step_size != 0; step_size /= 2) {

#pragma omp parallel for
            for (long long i = 0; i < arr.size() - step_size; ++i) {
                if (i % (step_size * 2) < step_size) {
                    bool asc = (i / (2 * max_step_size)) % 2 == 0;
                    if (asc && arr[i] > arr[i + step_size]) {
                        std::swap(arr[i], arr[i + step_size]);
                    }
                    else if (!asc && arr[i] < arr[i + step_size]) {
                        std::swap(arr[i], arr[i + step_size]);
                    }
                }
            }

        }
    }
}

// opencl version:
//__kernel void bitonic_sort(__global int* data, size_t n, size_t passes) {
//    size_t i = get_global_id(0);
//
//    for (size_t pass = 0; pass < passes; ++pass) {
//        size_t max_step_size = 1ull << pass;
//        for (size_t step_size = max_step_size; step_size != 0; step_size /= 2) {
//
//            barrier(CLK_GLOBAL_MEM_FENCE);
//
//            if (i >= n - step_size) continue;
//            if (i % (step_size * 2) >= step_size) continue;
//
//            bool asc = (i / (2 * max_step_size)) % 2 == 0;
//            if (asc && data[i] > data[i + step_size]) {
//                int temp = data[i];
//                data[i] = data[i + step_size];
//                data[i + step_size] = temp;
//            }
//            else if (!asc && data[i] < data[i + step_size]) {
//                int temp = data[i];
//                data[i] = data[i + step_size];
//                data[i + step_size] = temp;
//            }
//
//        }
//    }
//}