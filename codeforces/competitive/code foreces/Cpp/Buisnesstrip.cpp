#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin >> k;
    int arr[12];
    for(int i=0;i<12;i++){
        cin >> arr[i];
    }
   if(k==0){
        cout << 0 << endl;return 0;
    } 
    int n=12;
    sort(arr, arr + n, greater<int>()); 
    int sum=0;int count=1;
    for(int i=0;i<12;i++){
        sum=sum+arr[i];
        if(sum>=k){
        cout << count << endl;
            return 0;
        }
    count++;
    }
        cout << -1 << endl;
    return 0;
}