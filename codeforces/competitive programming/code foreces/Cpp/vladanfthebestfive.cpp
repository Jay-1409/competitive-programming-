#include<iostream>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int a=0;
    int b=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A'){
            a++;
        } else{
            b++;
        }
    }
    if(a>=b){
        cout << 'A' << endl;
    } else{
        cout << 'B' << endl;
    }
}
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}