#ifndef PLIB_H_
#define PLIB_H_
#include<iostream>
using namespace std;
namespace mylib{
//check for substring 
int isSubstring(string s1, string s2)
{
    // using find method to check if s1 is
    // a substring of s2
    if (s2.find(s1) != string::npos)
        return s2.find(s1);
    return -1;
}
//OUTPUTARRAY | ARRAYSIZE -- FUNCTION - arrOut,arrSize

    int arrOut(int *arr, int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }

//MAX|MIN OUTPUT -- FUNCTION - 
    int arrMax(int* arr,int size) {
        
        int maxVal = arr[0];
        for (int i = 1; i < size-1; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        return maxVal;
    }

    int arrMin(int* arr,int size) {
      
        int minVal = arr[0];
        for (int i = 1; i < size-1; i++) {
            if (arr[i] < minVal) {
                minVal = arr[i];
            }
        }
        return minVal;
    }

//TESTTEXT-FUNCTION - textTest
    void textTest(){
        cout << "Hello World!!" << endl;
    }

//SORT ARRAY-FUNCTION -arrSort
    void arrSort(int arr[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
}
#endif