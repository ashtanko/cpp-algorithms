#pragma once

#include <climits>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template<typename T>
void printArray(T *arr, int n) {
    cout << "[";
    for (int i = 0; i < n - 1; i++) {
        cout << arr[i] << ", ";
    }
    if (n >= 1)
        cout << arr[n - 1] << "]" << endl;
    else
        cout << "]" << endl;
}
