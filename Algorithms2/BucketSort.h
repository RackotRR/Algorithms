#pragma once
#include <span>
#include <algorithm>
#include <vector>

#include "QuickSort.h"

template<typename T>
void bucketSort(std::span<T> arr, size_t buckets_num) {
    auto [pMin, pMax] = std::minmax_element(std::begin(arr), std::end(arr));
    double max = *pMax;
    double min = *pMin;
    double range = (max - min) / buckets_num;

    // expecting uniform distribution
    using bucket_t = std::vector<T>;
    std::vector<bucket_t> buckets(buckets_num);
    for (auto& bucket : buckets) {
        bucket.reserve(arr.size() / buckets_num);
    }

    for (auto& item : arr) {
        double bucket_idx = std::clamp<double>((item - min) / range, 0, buckets_num - 1);
        buckets[static_cast<size_t>(bucket_idx)].push_back(item);
    }

    for (auto& bucket : buckets) {
        quickSort(std::span<T>(bucket));
    }

    for (size_t i = 0; auto& bucket : buckets) {
        for (auto& item : bucket) {
            arr[i++] = item;
        }
    }
}


template<typename T>
void bucketSort(std::span<T> arr) {
    bucketSort(arr, 16);
}