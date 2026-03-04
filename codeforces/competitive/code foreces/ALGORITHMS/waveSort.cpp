#include<iostream>
using namespace std;
void swap(int arr[],int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<n;i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr,i,i-1);
        }
        if(arr[i]>arr[i+1]){
            swap(arr,i,i+1);
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}