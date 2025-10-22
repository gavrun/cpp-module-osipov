// 141_SortArrayT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


// insertion sort for int[]
//void sorting(int arr[], int size) {
//    int j = 0;
//    for (int i = 0; i < size; ++i) {
//        int x = arr[i];
//        for (j = i - 1; j >= 0 && x < arr[j]; --j) {
//            arr[j + 1] = arr[j];
//        }
//        arr[j + 1] = x;
//    }
//}

// 
template <class T>
void sorting(T arr[], int size) {
    int j = 0;
    for (int i = 0; i < size; ++i) {
        T x = arr[i];
        for (j = i - 1; j >= 0 && x < arr[j]; --j) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = x;
    }
}

//
template <class T>
void printArray(const T* arr, int size) {
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << ";";
    std::cout << '\n';
}


int main()
{
    std::cout << "Hello World!\n";

    //int arr[] = { 9, 3, 17, 6, 5, 4, 31, 2, 12 };
    //int k1 = static_cast<int>(sizeof(arr) / sizeof(arr[0]));

    //sorting(arr, k1);

    //for (int i = 0; i < k1; ++i) {
    //    std::cout << arr[i] << ";";
    //}
    //std::cout << '\n';

    int arr[] = { 9, 3, 17, 6, 5, 4, 31, 2, 12 };
    double arrd[] = { 2.1, 2.3, 1.7, 6.6, 5.3, 2.44, 3.1, 2.4, 1.2 };
    char arrc[] = "Hello World!";

    int k1 = static_cast<int>(sizeof(arr) / sizeof(arr[0]));
    int k2 = static_cast<int>(sizeof(arrd) / sizeof(arrd[0]));
    int k3 = static_cast<int>(sizeof(arrc) / sizeof(arrc[0])) - 1; // skip '\0'

    sorting(arr, k1);
    sorting(arrd, k2);
    sorting(arrc, k3);

    //for (int i = 0; i < k1; ++i) std::cout << arr[i] << ";"; std::cout << '\n';
    //for (int i = 0; i < k2; ++i) std::cout << arrd[i] << ";"; std::cout << '\n';
    //for (int i = 0; i < k3; ++i) std::cout << arrc[i] << ";"; std::cout << '\n';

    printArray(arr, k1);
    printArray(arrd, k2);
    printArray(arrc, k3);

    return 0;
}
