#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool even(int n){
    if(n%2==0){
        return true;
    }return false;
}
void solve() {
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b&&b==c){
        cout<<1<<" "<<1<<" "<<1<< endl;
        return;
    } else{
        if(even(b+c)){
            cout<<1<<" ";
        } else{
            cout<<0<<" ";
        }
        if(even(c+a)){
            cout<<1<<" ";
        }else{
            cout<<0<<" ";
        }
        if(even(a+b)){
            cout<<1<<" ";
        }else{
            cout<<0<<" ";
        }
    }
    cout<<endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}