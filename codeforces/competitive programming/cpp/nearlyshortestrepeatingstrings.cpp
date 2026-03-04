#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include<
using namespace std;
int chc(string s, string s1){

}
void solve() {
    int n;cin>>n;
    int arr[26]={0};
    int ref=97;
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        arr[(int)s[i]-ref]++;
        // cout<<(int)s[i]-ref<<endl;
    }
    int max=INT64_MAX;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<s.size();j++){
            string temp=s.substr(i,j);
            if(chc(temp,s)<max){
                
            }
        }
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