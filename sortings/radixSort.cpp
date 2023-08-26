#include "sortings.hpp"

//12423 place = 100

void countingSort_radixSort(int* arr, int n, int place) {
    int* finalSort = new int[n];
    int* countArray = new int[10];
    for (int i = 0 ; i < 10 ; i ++) {
        countArray[i] = 0;
    }

    for (int i = 0 ; i < n ; i++) {
        countArray[(arr[i] / place) % 10]++;
    }

    for (int i = 1 ; i < n ; i++) {
        countArray[i] += countArray[i - 1];
    }

    for (int i = n - 1 ; i >= 0 ; i--) {
        finalSort[--countArray[(arr[i] / place) % 10]] = arr[i];
    }

    for (int i = 0 ; i < n ; i++) {
        arr[i] = finalSort[i];
    }

    delete[] countArray;
    delete[] finalSort;
}

void sortings::radixSort(int* arr, int n) {
    int max_element = getMax(arr, n);
    for (int place = 1 ; max_element / place > 0 ; place *= 10) {
        countingSort_radixSort(arr, n, place);
    }
}