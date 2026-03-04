#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n;
    cin>>n; 
    int cntn=0,cntp=0;
    int pr=1;
    int sum=0;
    vector<int>v;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
        if(x<0){
            cntn++;
        }else{
            cntp++;
        }
        pr*=x;
        sum+=x;
    }
    int op=0;
    while(cntn>cntp){
        cntn--;
        cntp++;
        op++;
    }
    if(cntn%2!=0){
        op++;
    }
    cout<<op<<endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}