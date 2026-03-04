#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
     cin >> n;
     vector<int> a;
     vector<int> b;
     int x;
     for(int i = 0; i < n; ++i){
        cin >> x;
        a.push_back(x);
     }
     int m;
     cin >> m;  
     for(int i = 0 ; i < m ;++i){
        cin >> x;
        b.push_back(x);
     }
     vector<int> ans(n);
     vector<int> bns(m);
    partial_sum(a.begin(),a.end(),ans.begin());
    partial_sum(b.begin(),b.end(),bns.begin());
    int one = *max_element(ans.begin(),ans.end());
    int tw = *max_element(bns.begin(),bns.end());

    cout << max(0,max(0,one)+max(0,tw))<<endl;

    //  if(n > m){
    //     for(int i = 0; i < m; i++){
    //         if(i & 1){
    //             ans.push_back(a[i]);
    //             bns.push_back(b[i]);
    //         }else{
    //             ans.push_back(b[i]);
    //             bns.push_back(a[i]);
    //         }
    //     }
    //     int j = ans.size();
    //     while(j < n){
    //         if(j & 1){
    //             ans.push_back(a[j]);
    //             bns.push_back(b[j]);
    //         }else{
    //             ans.push_back(b[j]);
    //             bns.push_back(a[j]);
    //         }
    //         j++;
    //     }
    //  }else{
    //     swap(n,m);
    //     for(int i = 0; i < m; i++){
    //         if(i & 1){
    //             ans.push_back(a[i]);
    //             bns.push_back(b[i]);
    //         }else{
    //             ans.push_back(b[i]);
    //             bns.push_back(a[i]);
    //         }
    //     }
    //     int j = bns.size();
    //     while(j < n){
    //         if(j & 1){
    //             ans.push_back(a[j]);
    //             bns.push_back(b[j]);
    //         }else{
    //             ans.push_back(b[j]);
    //             bns.push_back(a[j]);
    //         }
    //         j++;
    //     }
    //  }
    // //  for(auto i : ans){
    // //     cout << i << " ";
    // //  }
    // //  for(auto i : bns){
    // //     cout << i <<  " ";
    // //  }
    //  int pos = -1e9;
    //  for(int i = 0; i < ans.size();i++){
    //     for(int j = i + 1; j < ans.size();j++){
    //         int temsum = 0;
    //         int temsum2 = 0;
    //         for(int k = i ; k < j ; k++){
    //             temsum += ans[i];
    //             temsum2 += bns[i];
    //         }
    //         // cout << temsum << " "<< temsum2 << endl;
    //         pos = max(pos,temsum);
    //         pos = max(pos,temsum2);
    //     }
    //  }
    //  cout << pos << endl;
}
int main(){
int t;
cin >> t;

while(t--)solve();
return 0;
}