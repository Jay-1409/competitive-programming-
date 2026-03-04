#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;
void solve() {
    int n;cin>>n;
    vector<int> v;
    int x; double area;
    for(int i=0;i<n;i++){
        cin>>x;v.push_back(x);
    }
    sort(v.begin(),v.end());
    if(n%2!=0){
    double ar=3.1415926535*(double)v[0]*(double)v[0];
    int flg=0;
    for(int i=0;i<n;i++){
        if(flg==0){
            //blue
            flg=1;
        } else if(flg==1){
// cout<<ar<<endl;
            ar+=(double)v[i+1]*(double)v[i+1]*3.1415926535-v[i]*v[i]*3.1415926535;
            flg=0;
        }
    }
    area=ar;
    }
    else {
            double ar=0;
    int flg=1;
    for(int i=0;i<n-1;i++){
        if(flg==0){
            //blue
            flg=1;
        } else if(flg==1){
    // cout<<ar<<endl;
            ar+=(double)v[i+1]*(double)v[i+1]*3.1415926535-v[i]*v[i]*3.1415926535;
            flg=0;
        }
    } area=ar;
    }
    // int flg=0; int cnt=v[0]*v[0];
    // for(int i=0;i<n-1;i++){
    //     if(flg=0){
            
    //     }
    // }
    cout<<area<<endl;
}

int main() {
        solve();
    return 0;
}