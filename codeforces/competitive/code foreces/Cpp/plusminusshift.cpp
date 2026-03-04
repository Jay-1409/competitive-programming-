#include<iostream>
using namespace std;
int countP(char arr[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]=='+'){
            count ++;
        }
    }
    return count;
}
int countS(char arr[], int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]=='-'){
            count ++;
        }
    }
    return count;
}
int main(){
    int t;
    cin >> t;
    for(int test=0;test<t;test++){
        int n;
        cin >> n;
        char arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        int sum = abs(countP(arr,n) - countS(arr,n));
        cout << sum << endl;
    }
}