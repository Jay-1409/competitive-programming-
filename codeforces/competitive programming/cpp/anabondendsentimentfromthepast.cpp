#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n,k; cin>>n>>k;
    vector<int> a;
    vector<int> b;
    int x;
    for(int i=0;i<n;i++){
        cin>>x; a.push_back(x);
    }
    for(int i=0;i<k;i++){
        cin>>x;b.push_back(x);
    }
    sort(b.begin(),b.end(),greater<int>());
        int p=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            a[i]=b[p]; p++;
        }
    }
    int flg=0;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            flg=1; break;
        }
    }
    if(flg==1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
int main() {
    solve();
    return 0;
}