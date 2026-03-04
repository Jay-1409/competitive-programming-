#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>>p;
    vector<int> v;
    unordered_map<int,bool> mp;
    unordered_map<int,int> idx,idy;
    //T - a, F - b
    for(int i = 0 ; i < n ; i++){
        int x,y;
        cin >> x >> y;
        p.push_back({x,y});
        mp[x] = true;
        v.push_back(x);
        v.push_back(y);
        idx[x] = i;
        idy[y] = i;
    }
    string a(n,'0');
    string b(n,'0');
    sort(v.begin(),v.end());
    int k = 0 ;
    int taken  = 0;
    int mx = -1e9;
    while((2 * k) <= n){
        for(int i = taken ; i < k - taken; i ++){
            a[i] = '1';
            b[i] = '1';
            taken = i;
        }   
        int t = n - 2*k;
        int j = k;
        if(t > mx){
            mx = t;
            while(t-- && j <= n){
                if(mp[v[j]]){
                    a[idx[v[j]]] = '1';
                }else{
                    b[idy[v[j]]] = '1';
                }
                j++;
            }
        }
        k++;
    }
    cout << a << '\n';
    cout << b << '\n';
}
#undef int
int main(){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
int t = 1;
while(t--)solve();
return 0;
}
