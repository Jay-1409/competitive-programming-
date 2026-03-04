#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
bool is(vector<int> v,int x){
    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            return false;
        }
    } 
    return true;
}
void solve(){
    long long int n,k;
    cin >> n >> k;
    
    vector<long long int> v;
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            v.push_back(i);
        }
    }
n=(n+1)/2;
    for(int i=1;i<=n;i++){
        if((i)%2!=0 && 2*i<=n){
            v.push_back(2*i);
        }
    }
n=(n+1)/2;

    for(int i=1;i<=n;i++){
        if((i)%2!=0 && 3*i<=n){
            v.push_back(3*i);
        }
    }
n=(n+1)/2;

    for(int i=1;i<=n;i++){
        if((i)%2!=0 && 4*i<=n){
            v.push_back(4*i);
        }
    }
    
    // sort(v.begin(),v.end());
    // set<int> s(v.begin(),v.end());
    // vector<int> vs(s.begin(),s.end());
    // for(int i=0;i<vs.size();i++){
    //     cout << vs[i] << endl;
    // }
    // cout << vs[k-1] << endl;
    // vector<int> vo;
    // for(int i=0;i<v.size();i++){
    //     if(is(vo,v[i])){
    //         vo[i]=v[i];
    //     }
    // }f
    cout << v[k-1] << endl;
}

int main(){
    int t=0;
    cin>> t;
    for(int i=0;i<t;i++){
        solve();
    }
}