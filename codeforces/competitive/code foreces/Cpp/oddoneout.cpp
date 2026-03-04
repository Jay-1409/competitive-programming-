#include<iostream>
using namespace std;
void solve(){
    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    if(a==b){
        cout << c << endl;
    } else if(b==c){
        cout << a << endl;
    } else {
        cout << b << endl;
    }
}
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}