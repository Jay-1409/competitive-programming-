#include<iostream>
using namespace std;
int sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int temp;
            if(arr[j]<arr[i]){
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }    
    }
    for(int i=0;i<n;i++){
        cout << arr[i];
        cout << " ";
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,n);

}