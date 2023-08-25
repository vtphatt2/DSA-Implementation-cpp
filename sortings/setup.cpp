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