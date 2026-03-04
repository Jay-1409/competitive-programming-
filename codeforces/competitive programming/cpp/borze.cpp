#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    cin>>s;
    for(int i=0;i<s.size();i=i){
        if(s[i]=='.'){
            cout<<0;
            i++;
        }
        else{
            if(s[i+1]=='-'){
                cout<<2;
            }else{
                cout<<1;
            }
            i=i+2;
        }
    }
    cout<<endl;
}
int main() {
    solve();    
    return 0;
}