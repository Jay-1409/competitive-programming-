#include<iostream>
#include<vector>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> v;
        int cur=0;
    int s=0; int e=0; int flag=0;
    for(int i=0;i<n;i++){
        int x=0; cin>>x;
        v.push_back(x);
        if(flag==0){
            if(x==1){
                flag=1;
                s=i;
            }
        } else{
            if(x==1){
                e=i;
            }
        }
    }
        for(int i=s;i<=e;i++){
            if(v[i]==0){
                cur++;
            }
        }
    cout << cur << endl;

}
int main(){
    int t;
    cin>>t;
    while(t>0){
        solve();
        t--;
    }
}