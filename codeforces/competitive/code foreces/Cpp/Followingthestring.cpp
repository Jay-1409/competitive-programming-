#include<iostream>
using namespace std;
void solve(){
    int n;
    cin>> n;
    int arr[n];
    int in=97;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    string s;
    int let[26]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            if(arr[i]==let[j]){
                let[j]++;
                s +=char(97+j);
                break;
            }
        }
    }
    cout << s << endl;
}
int main(){
    int t; cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}