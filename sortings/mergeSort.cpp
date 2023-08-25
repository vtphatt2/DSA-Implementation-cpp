#include "sortings.hpp"

void recursive_mergeSort(int* arr, int n, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        recursive_mergeSort(arr, n, left, mid);
        recursive_mergeSort(arr, n, mid + 1, right);

        int* tmp = new int[right - left + 1];
        int i = left, j = mid + 1;
        int idx = 0;
        while (i <= mid + 1 || j <= right + 1) {
            if (i == mid + 1) {
                while (j <= right) {
                    tmp[idx] = arr[j];
                    idx++;
                    j++;
                }
                break ;
            }
            if (j == right + 1) {
                while (i <= mid) {
                    tmp[idx] = arr[i];
                    i++;
                    idx++;
                }
                break ;
            }
            if (arr[i] < arr[j]) {
                tmp[idx] = arr[i];
                i++;
                idx++;
            }
            else {
                tmp[idx] = arr[j];
                j++;
                idx++;
            }
        }
        for (int i = 0 ; i < right - left + 1 ; i++) {
            arr[i + left] = tmp[i];
        }

        delete[] tmp;
    }
} 

void sortings::mergeSort(int* arr, int n) {
    recursive_mergeSort(arr, n, 0, n - 1);
}