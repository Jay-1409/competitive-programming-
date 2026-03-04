#include<iostream>
#include<vector>
using namespace std;
bool check(vector<int>v,int x){
    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            return true;
        } 
    } return false;
}
void solve(){
    int n;cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x=0;cin >> x; v.push_back(x);
    }
    int sum=0;
    for(int i=0;i<v.size();i++){
        if(i==v.size()-1){
        sum=v[i]-v[0];
        if(check(v,sum)){
            cout << v[i]<< endl;
            return;
        }
        }else{
            sum=v[i]-v[i+1];        
            if(check(v,sum)){
            cout << v[i]<< endl;
            return;
        }
        }
    }
}
int main(){
    int t;cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}