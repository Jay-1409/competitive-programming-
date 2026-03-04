#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int a;
    int b;
    int n;
    cin>>a>>b>>n;
    if(n%3==0){
        cout<<a<<endl; 
    } else if(n%3==1){
        cout<<b<<endl;
    }else{
        cout<<(a^b)<<endl;
    }
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}