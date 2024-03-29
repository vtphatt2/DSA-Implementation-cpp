#include <iostream>
#include <fstream>

void readData(int* &arr, int &n);
void displayArray(int* arr, int n);
void swap(int &x, int &y);
int getMax(int* arr, int n);

class sortings {
    public :
        static void bubbleSort(int* arr, int n);
        static void insertionSort(int* arr, int n);
        static void selectionSort(int* arr, int n);
        static void heapSort(int* arr, int n);
        static void mergeSort(int* arr, int n);
        static void quickSort(int* arr, int n);
        static void countingSort(int* arr, int n);
        static void radixSort(int* arr, int n);
};