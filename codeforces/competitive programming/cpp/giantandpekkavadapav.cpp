#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
    int x=0;
    cin >> x;
    int arr[x];int count=0;
    for(int j=0;j<x;j++){
        cin>> arr[j];
        if(arr[j]<0){
            count++;
            break;
        }
    }
    if(count>0){
        cout <<"NO"<< endl;
    } else{
        cout << "YES"<< endl;
    }
    }
    return 0;
}