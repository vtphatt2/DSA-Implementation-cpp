#include "sortings.hpp"

void readData(int* &arr, int &n) {
    std::ifstream fin("data.txt");
    if (!fin.is_open()) {
        std::cout << "Error opening file !";
        return ;
    }
    fin >> n;
    arr = new int[n];
    for (int i = 0 ; i < n ; i++) {
        fin >> arr[i];
    }
    fin.close();
}

void displayArray(int* arr, int n) {
    for (int i = 0 ; i < n ; i++) {
        std::cout << arr[i] << " ";
    }
}

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void sortings::bubbleSort(int* arr, int n) {
    for (int i = 0 ; i < n - 1 ; i++) {
        for (int j = 0 ; j < n - i - 1 ; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sortings::insertionSort(int* arr, int n) {
    for (int i = 1 ; i < n ; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; 
            j--;
        }
        arr[j + 1] = key;
    }
}

void sortings::selectionSort(int* arr, int n) {
    for (int i = 0 ; i < n - 1 ; i++) {
        for (int j = i ; j < n ; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void heapify(int* arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    } 
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void sortings::heapSort(int* arr, int n) {
    for (int i = n/2 - 1 ; i >= 0 ; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1 ; i > 0 ; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

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