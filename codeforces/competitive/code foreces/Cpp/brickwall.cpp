#include<iostream>
#include<cmath>
using namespace std;
void solve(){
    int n,m;
    cin >> n >> m;
    cout << (m/2)*n << endl;
}
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }   
}