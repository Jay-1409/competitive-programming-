#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isV(char x) {
    string s="aeiouy";
    string s1="AEIOUY";
    for(int i=0;i<s.size();i++){
        if(x==s[i]||x==s1[i]){
            return true;
        }
    }return false;
}
void solve() {
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        if(!isV(s[i])){
            cout<<"."; cout<<(char)tolower(s[i]);continue;
        }
    }
}
int main() {
    int t;
        solve();
    return 0;
}