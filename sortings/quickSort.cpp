#include "sortings.hpp"

//the pivot selected in each step is the last element of each subarray

void recursive_quickSort(int* arr, int n, int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int j = left;
        for (int i = left ; i < right ; i++) {
            if (arr[i] < pivot) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
        swap(arr[right], arr[j]);
        recursive_quickSort(arr, n, left, j - 1);
        recursive_quickSort(arr, n, j + 1, right);
    }
}

void sortings::quickSort(int* arr, int n) {
    recursive_quickSort(arr, n, 0, n - 1);
}