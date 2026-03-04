#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> v;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<n-2;i++){
        if(v[i]<0) break;
		v[i+1]-=(2*v[i]);
		v[i+2]-=v[i];
		v[i]-=v[i];
        // while(flg==0){
        //     if((v[i-1]>0 && v[i]>=2)&&v[i+1]>0){
        //         v[i-1]--;
        //         v[i]=v[i]-2;
        //         v[i+1]--;
        //     }else{
        //         flg++;
        //     }
        // }
    }
    	cout<<((count(v.begin(),v.end(),0)==n)?"yes":"no")<<endl;

    // for(int i=0;i<v.size();i++){
    //     if(v[i]!=0){
    //         cout<<"NO"<<endl; return;
    //     }
    // }
    // cout<<"YES"<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}