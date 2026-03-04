#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    int ans;
    cin>>n;int j;
    char arr[2][n];
    for(int i=0;i<2;i++){
        for(j=0;j<n;j++){
            cin>>arr[i][j];
        }
        if(i==1&&j==n-1){
            ans=(int)arr[i][j];
        }
    }
    vector<int> v;
    int x=0;
    int i=0;
    j=0;
    int flag=0;
    while(n>0){
        if(arr[0][i]=='0'){
            v.push_back(0);
            i++;
        } else if(arr[0][i]=='1'){
            if(arr[1][i]=='0'){
                v.push_back(0);
                j=1;
            }
        } else{
            v.push_back(1);
            i++;
        }
        n--;
    }
    v.push_back(ans);
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
    cout<<endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}