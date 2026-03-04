#include<iostream>
#include<vector>
using namespace std;
void solve(){
    int n;
    cin >> n;
    char arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    vector<int> v;

    for(int i=0;i<n;i++){
        int temp=0;
        for(int j=0;j<n;j++){
            if(arr[j][i]=='1'){
                temp++;
            }
        }
        // if(temp%2!=0){
        //     cout << "TRIANGLE" << endl;
        //     return;
        // }
        if(temp!=0){
            v.push_back(temp);
        }
    }
    // cout << v.size();
    for(int i=0;i<v.size()-1;i++){
        // cout << v[i] << endl;
        if(v[i]!=v[i+1]){
            cout << "TRIANGLE" << endl;
            return;
        }
    }
    cout << "SQUARE" << endl;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
}