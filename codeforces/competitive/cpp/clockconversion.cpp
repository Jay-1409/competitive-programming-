#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;

void solve() {
    string s; cin>>s;
    string sf=s.substr(0,2);
    // cout<<sf<<endl;
    string sb=s.substr(3,5);
    int f=stoi(sf);
    string bhd;
    int ans;
    if(f==0){
        ans=12;
        bhd="AM";
        cout<<ans<<":"<<sb<<" "<<bhd<<endl; return;
    }
    if(f>12){
        ans=f-12;
        if(ans==0){
            bhd="AM";
        }else{
            bhd="PM";
        }    string sn="0";

    if(ans<10){
        sn=sn+to_string(ans);
    cout<<sn<<":"<<sb<<" "<<bhd<<endl; return;
    }
        cout<<ans<<":"<<sb<<" "<<bhd<<endl; return;
    }else{
        ans=f;
    }
    if(f>=12){
        bhd="PM";
    }else{
        bhd="AM";
    }
    string sn="0";
    if(ans<10){
        sn=sn+to_string(ans);
    cout<<sn<<":"<<sb<<" "<<bhd<<endl; return;
    }
    cout<<ans<<":"<<sb<<" "<<bhd<<endl; return;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}