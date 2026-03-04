#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int a;
    int b;
    int c;
    cin>>a>>b>>c;
    if(a+b>=10){
        cout<<"yes"<< endl;
    } else if(b+c>=10){
        cout<<"yes"<<endl;
    } else if(c+a>=10){
        cout<<"yes"<<endl;
    } else{
        cout<<"no"<< endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}