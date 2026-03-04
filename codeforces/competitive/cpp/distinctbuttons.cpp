#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin>>n;
    int x,y;
    int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        if(x>0){
            cnt1++;
        } else if(x<=0){
            cnt2++; 
        }
        if(y>0){
            cnt3++;
        } else if(y<=0){
            cnt4++;
        }
    }
    if(((cnt1==n||cnt2==n)||cnt3==n)||cnt4==n){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}