#include<iostream>
using namespace std;
int fact(int x){
    int factorial=1;
    for(int i=1;i<=x;i++){
        factorial=factorial*i;
    }
    return factorial;
}
int ncr(int n,int r){
    int upper=fact(n);
    int lower=(fact(n-r))*(fact(r));
    return upper/lower;
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << ncr(i,je);
        }
        cout << endl;
    }
}