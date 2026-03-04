#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    string x;
    cin >> x;
    int cnt = 0;
    size_t pos = 0 ;

    while((pos = s.find(x, pos)) != string::npos){
        cnt++;
        pos++;
    }
    cout << cnt << endl;

}
int main(){
int t = 1;

while(t--)solve();
return 0;
}