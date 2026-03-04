#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> v;
    int x;long long int sum=0;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
        sum+=x;
    }
    int each=sum/n;
    for(int i=0;i<n-1;i++){
        if(v[i]<each){
            cout<<"NO"<<endl;return;
        }
        int temp=each-v[i];
        v[i]+=temp;
        v[i+1]-=temp;
    }
    cout<<"YES"<<endl;
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}