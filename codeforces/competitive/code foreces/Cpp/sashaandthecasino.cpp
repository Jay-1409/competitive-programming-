#include<iostream>
using namespace std;
void solve(){
    int k,x,a;
    cin >> k >> x >> a;
    int b=a;

    if(a<=x||(a-x)*k<=a){
        cout << "NO" << endl;
        return;
    }
    for(int i=0;i<x;i++){
        if(a<=0){
            cout << "NO" << endl;
            return;
        }
        a--;
        // cout << a << endl;
    }
    a--;
    a=a+ a*(k-1);
    // cout << a << endl;
    // cout << b << endl;
    if(a>b){
        cout << "YES"<< endl;
    } else{
        cout << "NO"<< endl;
    }
}
int main(){
    int t;
    cin >> t;
    while(t>0){
        solve();
        t--;
    }
}