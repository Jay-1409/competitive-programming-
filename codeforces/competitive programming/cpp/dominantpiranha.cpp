#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int find(vector<int> v,int x){
    for(int i=0;i<v.size();i++){
        if(v[i]==x && i==v.size()-1){
            if(v[i]!=v[i-1]){
            return i+1;
        }
        if(v[i]==x){
            if(v[i]!=v[i+1]&&i==0){
                // cout<<v[i]<<" "<<v[i+1]<<endl;
            return i+1;
            } else{
                if(v[i]!=v[i+1] || v[i]!=v[i-1]){
                    return i+1;
                }
            }
        }
    }
}
}
void solve() {
    int n;cin>>n;                       
    vector<int> a;
    int x;
    int max=0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x>max){
            max=x;
        }
        a.push_back(x);
    }
    int flg=0;
    for(int i=0;i<a.size()-1;i++){
        if(a[i]!=a[i+1]){
            flg=1; break;
        }
    }
    if(flg==0){
        cout<<-1<<endl; return;
    }
    // sort(a.begin(),a.end());
    // cout<<a[a.size()-1]<<endl;
    int ans=find(a,max);
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