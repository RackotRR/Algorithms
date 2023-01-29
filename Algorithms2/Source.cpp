#include <vector>
#include <iostream>
#include <format>
#include <string>
#include <algorithm>

#include "LinearSearch.h"
#include "BinarySearch.h"
#include "FibonacciSearch.h"
#include "InterpolationSearch.h"
#include "ExponentialSearch.h"
#include "JumpSearch.h"
#include "TernarySearch.h"

#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "QuickSort3Way.h"

#define testSort(N) testSortFunction(N, #N)
#define testSearch(N) testSearchFunction(N, #N)

using searchFunc_t = int* (*)(const int& x, std::span<int> arr);
using sortFunc_t = void (*)(std::span<int> arr);

void testSearchFunction(searchFunc_t searchFunc, std::string name) {
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(rand() % 100);
    }
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    int count = 0;
    int total = 0;
    for (int i = -50; i < 50; ++i) {
        auto result = searchFunc(i, std::span<int>(vec));
        auto result_to_be = linearSearch(i, std::span<int>(vec));
        if (result == result_to_be) {
            ++count;
        }
        ++total;        
    }

    std::cout << name << ": " << (count == total ? "success" : "fail") << std::endl;
}

void testSortFunction(sortFunc_t sortFunc, std::string name) {
    std::vector<int> vec1, vec2;
    int n = 1000;
    for (int i = 0; i < n; ++i) {
        int value = rand() % 100;
        vec1.push_back(value);
        vec2.push_back(value);
    }

    sortFunc(std::span<int>(vec1));
    std::sort(vec2.begin(), vec2.end());

    std::cout << name << ": ";
    for (int i = 0; i < n; ++i) {
        if (vec1[i] != vec2[i]) {
            std::cout << "error" << std::endl;
            return;
        }
    }
    std::cout << "success" << std::endl; 
}


int main() {
    testSort(insertionSort);
    testSort(bubbleSort);
    testSort(selectionSort);
    testSort(mergeSort);
    testSort(quickSort);
    testSort(quickSort3Way);

    testSearch(binarySearch);
    testSearch(exponentialSearch);
    testSearch(interpolationSearch);
    testSearch(ternarySearch);
    testSearch(fibonacciSearch);
    testSearch(jumpSearch);
    return 0;
}