#include<iostream>
using namespace std;
void solve(){
    int x; int n=26;
    cin >> x;
    int a,b,c;
    a=97;
    b=97;
    c=97;
    if(x<28){
        int temp=x-2-1;
    
        cout << (char)a << (char)b << (char)(97+temp) << endl;
    } else if(x>=28&&x<=52){
        c=122;
        int temp=x-26-2;
        cout << (char)a << (char)(97+temp) << (char)c << endl;   
    } else{
        c=122;
        b=122;
        int temp=x-52-1;
        cout << (char)(97+temp) << (char)b << (char)c << endl;   
    }
}
int main(){
    int t; cin>> t;int i=0;
    for(int i=0;i<t;i++){
        solve();
    }
}