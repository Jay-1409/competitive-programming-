#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(){
    int n,m; cin >> n >> m;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    for(int i=0;i<n;i++){
        int x;cin>> x;
        v1.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;cin>> x;
        v2.push_back(x);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end(),greater<int>());
    int p=m/2;
    for(int i=0;i<p-1;i++){
        cout << v1[i]<< v2[i] << endl;
        v3.push_back(v1[i]-v2[i]);
    }
    cout<< "part"<< endl;
    int j=n;
    for(int i=m-2;i>p-1;i--){
        cout << v1[i] << v2[j-1] << endl;
        v3.push_back(v1[i]-v2[j-1]);
        j--;
    }
    int sum=0;
    for(int i=0;i<v3.size();i++){
        cout << v3[i]<< endl;
        sum=sum+abs(v3[i]);
    }
    cout<< sum << endl;
}
int main(){
    int t; cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}