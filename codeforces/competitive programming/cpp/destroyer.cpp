#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v;
    vector<int> ans;
    int x; 
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());    
    int cur = v[0]; 
    int cnt = 1; 
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            cnt++; 
        } else {
            ans.push_back(cnt);
            cnt = 1; 
            cur = v[i]; 
        }
    }
    ans.push_back(cnt); 
    int op=ans[0];
    cout<<op<<endl;
    for(int i=1;i<ans.size();i++){
        cout<<ans[i]<<" "<<op<<endl;
        if(ans[i]+1>op){
            cout<<"NO"<<endl; 
            return;
        }
        op=ans[i];
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
