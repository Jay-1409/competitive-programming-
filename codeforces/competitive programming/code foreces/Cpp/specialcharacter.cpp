#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n;
    cin>>n;
    if(n%2!=0){
        cout<<"NO"<<endl;return;
    }
    vector<char> s;
    int flg=0; int cnt=0;
    for(int i=0;i<n;i++){
        if((flg==0)&&(cnt==0 ||cnt==1)){
        s.push_back('A');
        cnt++;
        if(cnt==2){
            flg=1;
        }
        } else if((cnt==2||cnt==1)&&flg==1){
            s.push_back('B');
            cnt--;
            if(cnt==0){
                flg=0;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<s.size();i++){
        cout<<s[i];
    } cout<<endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}