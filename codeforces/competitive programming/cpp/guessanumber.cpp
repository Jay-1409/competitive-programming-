#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    int y = 0;
    char ye = 'Y';
    char no = 'N';
    while(n--){
        string s;
        cin >> s;
        int x;
        cin >> x;
        char c;
        cin >> c;

        if(c == ye){
            if(s == ">="){
                y = x;
            }
        }
    }
}
int main(){
int t = 1;

while(t--)solve();
return 0;
}