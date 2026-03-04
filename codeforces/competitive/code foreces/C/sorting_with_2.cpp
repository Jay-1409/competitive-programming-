#include<iostream>
using namespace std;
int main(){
int t;
cin >> t;
for(int i=1;i<=t;i++){
    int check=0,temp=0;
    int n=0;
    cin >> n;
    int arr[n];
    string ans[n];
    for(int k=0;k<n;k++){
        cin >> arr[i];
    }
        for (int l = 0; i < n; l++){
        for (int m = l; m < n; m++){
            if (arr[l] > arr[m+1]){
                temp = arr[l];
                arr[l] = arr[m+1];
                arr[m+1] = temp;
            }
        }
    }
    for(int j=1;j<=(n-1);j++){
        if(arr[i]>arr[i+1]){
            check++;
        }
    }   
    if(check>=1){cout<<"NO";}
    else{cout << "YES";}
}
}