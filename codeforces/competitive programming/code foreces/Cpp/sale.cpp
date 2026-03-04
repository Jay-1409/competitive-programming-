#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> v;
    int x;
    int flg=0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x<0){
            flg++;
        }
        v.push_back(x);
    }
    if(flg==0){
        cout<<0<<endl; return;
    }
    vector<int> sa;
    sort(v.begin(),v.end());
    int sum=0;
    sa.push_back(v[0]);
    int i;
    for( i=0;i<m;i++){
        sum+=v[i];
        // cout<<sa[i]<<" "<<sum<<endl;    
        if((abs(sa[i])>abs(sum))||sum>0){
            sum=sa[i];
        break;       
        }
        sa.push_back(sum);
    }
    cout<<abs(sum)<<endl;
}
int main() {
        solve();   
    return 0;
}
