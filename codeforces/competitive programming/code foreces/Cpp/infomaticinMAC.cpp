#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MEX(vector<int> v,int x,int y){
    int sm=1;
    for(int i=x;i<y;i++){
        if(v[i]==sm){
            sm++;
        }
    }
    return sm;
}
void solve() {
    int n;
    cin>>n;
    vector<int>v;
    int x; 
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    int count=0;
    int i1=0;
    int i2=1;
    vector<int> v1;
    // for(int i=0;i<n;i++){
    //     x=MEX(v,i1,i2);
    //     v1.push_back(x);
    //     cout<<x;
    //     i1++;
    //     i2++;
    // }
      vector<int> v1;
    vector<int> v2;
    for(int i=0;i<=v.size();i++){
        for(int j=i+1;j<=v.size();j++){
            x=MEX(v,i,j);
            if(j==1){
            v2.push_back(x);
            } else{
                if(v2[i-1]==v2[i]){
                    v1.push_back(i);
                }
            }
            
            cout<<i+1<<" "<<j+1 <<endl;
        }
    }
    sort(v2.begin(),v2.end());
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<endl;
    }
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}