#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;

void solve() {
    int s;char d; cin>>s; cin>>d;
    string n; cin>>n;
    int flg=0;
    for(int i=0;i<n.size();i++){
        if(n[i]<d){
            if(flg==0){
                cout<<d;
                flg=1;
        }
        }
    cout<<n[i];
        if(flg==0){
            if(i==n.size()-1){
                cout<<d;
            }
        } 
}    cout<<endl;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}