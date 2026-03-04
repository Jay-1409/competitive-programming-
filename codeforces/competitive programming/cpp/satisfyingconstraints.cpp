#include<iostream>
using namespace std;
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
void solve(){
    int n; cin>> n;int count=0;
    int arr1[n];
    int arr2[n];
    int j=0,k=0;
    int temp=0;
    int x=0,y=0;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        if(x==1){
            arr1[i]=y;j++;
        }
        if(x==2){
            arr2[i]=y;k++;
        }
        if(x==3){
         if(y!=temp){
            count++;
            temp=y;
        }
    }
}
    int max=arrMax(arr1,j);
    int min=arrMin(arr2,k);
    cout << min-max-count+12 << endl;
}
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
}