#include<iostream>
using namespace std;
void generateSequence(int n) {
    int count = 0; int num=1;
    for (int i = 1; count < n; i++) {
        if (i % 3 != 0 && i%10!=3) {
            num=i;
            count++;
        }
    }
    cout << num << endl;
}
void solve(){
    int x; 
    cin>>x; int count=0;int i=0;
    generateSequence(x);
}
int main(){
    int t;cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}