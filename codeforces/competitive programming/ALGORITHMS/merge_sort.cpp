#include<iostream>
#include "plib.h"
using namespace mylib;
using namespace std;
void merge(int arr[],int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++;k++;
        }else{
            arr[k]=b[j];
            j++;k++;
        }
    }

    while(i<n1){
        arr[k]=a[i];
        i++;k++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++;k++;
    }
}
void mergeSort(int arr[], int l, int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main(){
    int n;
    cout << "ENTER THE SIZE OF THE ARRAY" << endl;
    cin >> n;
    cout << "ENTER THE ARRAY ELEMENTS" << endl;
    int arr[n];
    int size=0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        size++;
    }
    mergeSort(arr,0,size);
    for(int i=0;i<size;i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
    return 0;

}