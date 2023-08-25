#include "sortings.hpp"

int main() {
    int* arr;
    int n;
    readData(arr, n);
    sortings::heapSort(arr, n);
    displayArray(arr, n);
    delete[] arr;
    return 0;
}
