#include<iostream>
using namespace std;
int arrSum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    return sum;
}
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
int main(){
    int n; cin >> n;
    int arr1[n];
    int arr2[n];
    arrSort(arr1,n);
    arrSort(arr2,n);
   for(int i=0;i<n;i++){
        cin >> arr1[i];
   }
   for(int i=0;i<n;i++){
        cin >> arr2[i];
    }
    // 3 4 2 2 3 5
    // 1 3 4 3 1 2
    cout << arrSum(arr1,n);
    cout << arrSum(arr2,n);
    
}
