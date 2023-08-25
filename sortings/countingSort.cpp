#include "sortings.hpp"

int getMax(int* arr, int n){
    int max_value = arr[0];
    for (int i = 1 ; i < n ; i++){
        if (arr[i] > max_value){
            max_value = arr[i];
        }
    }
    return max_value;
};

void sortings::countingSort(int* arr, int n) {
    int size = getMax(arr, n) + 1;
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
        arr[--countArray[arr[i]]] = arr[i];
    }

    delete[] countArray;
}