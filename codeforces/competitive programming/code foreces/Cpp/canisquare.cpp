#include<iostream>
#include<vector>
using namespace std;
void solve();
void hell();

int main(){
    cout << "M" << endl;
    solve();
    return 0;
}
void solve(){
    hell();
}
void hell(){
    cout << "WELCOME TO HELL " << endl;
    solve();
}