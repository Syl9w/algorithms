//
//  algs.h
//  FinalProject
//
//  Created by Sultan on 5/6/21.
//

namespace A
{
    class algs
    {

    public:
        
        void IS(int n);
        void BS(int n);
        void BSearch(int n);
        void SS(int n);
        void QS(int n);
        void MS(int n);
        

    private:
        float* generateArray(int n);
        
        void printArray(float* arr, int n);
        void insertionSort(float* arr,int n);
        void bubbleSort(float* arr,int n);
        int binarySearch(float* arr, int l, int r, float element);
        void selectonSort(float* arr, int n);
        void quickSort(float* arr, int low, int high);
        int partition(float* arr, int ow, int high);
        void mergeSort(float* arr, int l, int r);
        void merge(float* arr, int l, int m, int r);
    };

}
