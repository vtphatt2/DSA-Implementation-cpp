#include "sortings.hpp"

int main() {
    int* arr;
    int n;
    readData(arr, n);
    sortings::selectionSort(arr, n);
    displayArray(arr, n);
    delete[] arr;
    return 0;
}