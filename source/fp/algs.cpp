//
//  algs.cpp
//  FinalProject
//
//  Created by Marlen on 5/6/21.
//

#include "algs.h"
#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace A;
using namespace std;

float* algs::generateArray(int n) {
    float *array = new float[n];
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 10000;
    }
    return array;
}


void algs::IS(int n) {
    float * arr = algs::generateArray(n);
    cout << "Insertion Sort with array of "<<n<<" elements:" << endl;
    cout << "Randomised array ";
    auto start = high_resolution_clock::now();
    algs::insertionSort(arr, n);
    auto stop = high_resolution_clock::now();
    duration<double> duration = stop - start;
    cout << duration.count() << " sec." << endl;

    cout << "Sorted array ";
    start = high_resolution_clock::now();
    algs::insertionSort(arr, n);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << duration.count() << " sec." << endl;

    
    cout << "Reversed array ";
    for (int low = 0, high = n - 1; low < high; low++, high--) {
        swap(arr[low], arr[high]);
    }
    start = high_resolution_clock::now();
    algs::insertionSort(arr, n);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << duration.count() << " sec." << endl;
    delete[] arr;
}

void algs::BS(int n) {
    float* arr = algs::generateArray(n);
    cout << "Bubble Sort with array of " <<n<<" elements:" << endl;
    cout << "Randomised array ";
    auto start = high_resolution_clock::now();
    algs::bubbleSort(arr, n);
    auto stop = high_resolution_clock::now();
    duration<double> duration = stop - start;
    cout << duration.count() << " sec." << endl;

    cout << "Sorted array ";
    start = high_resolution_clock::now();
    algs::bubbleSort(arr, n);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << duration.count() << " sec." << endl;

    cout << "Reversed array ";
    for (int low = 0, high = n - 1; low < high; low++, high--) {
        swap(arr[low], arr[high]);
    }
    start = high_resolution_clock::now();
    algs::bubbleSort(arr,n);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << duration.count() << " sec." << endl;
    delete[] arr;
}

void algs::BSearch(int n) {
    
    
    cout << "Binary search with array of " <<n<<" elements:" << endl;
    float* arr = algs::generateArray(n);
    algs::selectonSort(arr, n);
    int i = rand()%1000;
    
    auto start = high_resolution_clock::now();
    binarySearch(arr, 0, n, arr[i]);
    auto stop = high_resolution_clock::now();
    duration<double> duration = stop - start;
    cout << duration.count() << " sec." << endl;
    
    delete[] arr;
}

void algs::SS(int n) {
    float* arr = algs::generateArray(n);
    cout << "Selection Sort with array of "<<n<<" elements :" << endl;
    cout << "Randomised array ";
    auto start = high_resolution_clock::now();

    algs::selectonSort(arr, n);
    auto stop = high_resolution_clock::now();
    duration<double> duration = stop - start;
    cout << duration.count() << " sec." << endl;

    cout << "Sorted array ";
    start = high_resolution_clock::now();
    algs::selectonSort(arr, n);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << duration.count() << " sec." << endl;
    
    for (int low = 0, high = n - 1; low < high; low++, high--) {
        swap(arr[low], arr[high]);
    }
    cout << "Reversed array ";
    start = high_resolution_clock::now();
    algs::selectonSort(arr, n);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << duration.count() << " sec." << endl;
    delete[] arr;
}

void algs::QS(int n) {
    float* arr = algs::generateArray(n);
    cout << "Quick Sort with array of "<<n<<" elements:" << endl;
    cout << "Randomised array ";
    auto start = high_resolution_clock::now();
    algs::quickSort(arr, 0, n);
    auto stop = high_resolution_clock::now();
    duration<double> duration = stop - start;
    cout << duration.count() << " sec." << endl;

    cout << "Sorted array ";
    start = high_resolution_clock::now();
    algs::quickSort(arr, 0, n);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << duration.count() << " sec." << endl;
    for (int low = 0, high = n - 1; low < high; low++, high--) {
        swap(arr[low], arr[high]);
    }
    cout << "Reversed array ";
    start = high_resolution_clock::now();
    algs::quickSort(arr, 0, n);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << duration.count() << " sec." << endl;
    delete[] arr;
}

void algs::MS(int n) {
    float* arr = algs::generateArray(n);
    cout << "Merge Sort with array of "<<n<<" elements:" << endl;
    cout << "Randomised array ";
    auto start = high_resolution_clock::now();
    algs::mergeSort(arr, 0, n);
    auto stop = high_resolution_clock::now();
    duration<double> duration = stop - start;
    cout << duration.count() << " sec." << endl;

    cout << "Sorted array ";
    start = high_resolution_clock::now();
    algs::mergeSort(arr, 0, n);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << duration.count() << " sec." << endl;

    for (int low = 0, high = n - 1; low < high; low++, high--) {
        swap(arr[low], arr[high]);
    }

    cout << "Reversed array ";
    start = high_resolution_clock::now();
    algs::mergeSort(arr, 0, n);
    stop = high_resolution_clock::now();
    duration = stop - start;
    cout << duration.count() << " sec." << endl;
    delete[] arr;
}




void algs::printArray(float* arr, int n)
{

    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";
    cout << endl;
}


void algs::insertionSort(float* arr, int n)
{



    int i;
    float key;
    int j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

    }


}

void algs::bubbleSort(float* arr, int n)
{

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }


}

int algs::binarySearch(float* arr, int l, int r, float element)
{

    int midp = l + ((r - l) / 2);
    if (arr[midp] == element) {
        return midp;
    }
    else {
        if (arr[midp] > element) {
            return binarySearch(arr, l, midp - 1, element);
        }
        if (arr[midp] < element) {
            return binarySearch(arr, midp + 1, r, element);
        }

    }

    return -1;
}

void algs::selectonSort(float* arr, int n)
{

    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i; j < n; j++) {
            if (arr[min] > arr[j]) min = j;
        }
        swap(arr[i], arr[min]);
    }

}

int algs::partition(float* arr, int low, int high)
{
    float pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }


    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void algs::quickSort(float* arr, int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void algs::merge(float* arr, int l, int m, int r)
{
    const int n1 = m - l + 1;
    const int n2 = r - m;
    
    float* L = new float[n1];
    float* R = new float[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];


    int i = 0, j = 0;

    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    delete[] L;
    delete[] R;
}


void algs::mergeSort(float* arr, int l, int r)
{
    if (r <= l) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);

}

