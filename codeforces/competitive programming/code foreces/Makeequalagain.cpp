#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> v;
    int x; 
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    int flag=0;
    for(int i=0;i<n-1;i++){
        if(flag!=0){
            break;
        }
        if(v[i]!=v[i+1]){
            flag=1;
        }
    }
    if(flag==0){
        cout<<0<<endl;return;
    }
    int s=1;
    for(int i=1;i<n;i++){
        if(v[i]==v[0]){
            s++;
        } else{
            break;
        }
    }
    int e=1;
    for(int i=n-2;i>=0;i--){
        if(v[i]==v[n-1]){
            e++;
        }else{
            break;
        }
    }
    int ans=n;
    if(v[0]==v[n-1]){
        ans-=s;
        ans-=e;
    } else{
        ans-=max(s,e);
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}