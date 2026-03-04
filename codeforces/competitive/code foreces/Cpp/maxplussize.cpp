#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int mx1 = 0;
    int mx2 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    int x = 0;
    for(int i = 0 ; i < n; i++){
        cin >> x;
        if(i & 1){
            cnt1++;
            mx1 = max(mx1,x);
        }else{
            cnt2++;
            mx2 = max(mx2,x);
        }
    }
    cout << max(mx1 + cnt1 , mx2 + cnt2) << endl;
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}