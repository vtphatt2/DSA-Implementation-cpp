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

void sortings::bubbleSort(int* &arr, int n) {
    for (int i = 0 ; i < n - 1 ; i++) {
        for (int j = 0 ; j < n - i - 1 ; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sortings::selectionSort(int* &arr, int n) {
    for (int i = 0 ; i < n - 1 ; i++) {
        for (int j = i ; j < n ; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}