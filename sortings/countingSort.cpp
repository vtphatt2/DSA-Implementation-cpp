#include "sortings.hpp"

void sortings::countingSort(int* arr, int n) {
    int size = getMax(arr, n) + 1;
    int* finalSort = new int[n];

    int* countArray = new int[size];
    for (int i = 0 ; i < size ; i++) {
        countArray[i] = 0;
    }
    for (int i = 0 ; i < n ; i++) {
        countArray[arr[i]]++;
    }
    for (int i = 0 ; i < size - 1 ; i++) {
        countArray[i + 1] += countArray[i];
    }
    for (int i = 0 ; i < n ; i++) {
        finalSort[--countArray[arr[i]]] = arr[i];
    }
    for (int i = 0 ; i < n ; i++) {
        arr[i] = finalSort[i];
    }

    delete[] finalSort;
    delete[] countArray;
}