#include<iostream>
#include<vector>
using namespace std;
void solve(){
    int x;cin >> x;
    if(x<=4){
        cout << "Bob"<< endl;
    } else{
        cout << "Alice"<< endl;
    }
}
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}