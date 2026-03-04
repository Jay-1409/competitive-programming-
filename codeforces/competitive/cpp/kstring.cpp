#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int k;cin>>k;
    int ref=97;
    int arr[26]={0};
    string s; cin>>s;
    vector<int>it;
    if(s.size()%k!=0){
        cout<<-1<<endl;return;
    }
    for(int i=0;i<s.size();i++){
        arr[(int)s[i]-ref]++;
    }
    int max=arr[0];
    vector<int> v;
    for(int i=0;i<26;i++){
            if(arr[i]%k!=0){
                cout<<-1<<endl;return;
            }
    }
    // if(max>k){
    //     cout<<-1<<endl;return;
    // }
    string ans="";
                                    for(int i=0;i<26;i++){
                                        for(int j=0;j<arr[i]/k;j++){
                                            ans+=(i+'a');
                                        }
                                    }
                                    string f="";
                                    for(int i=0;i<k ;i++){
                                    f+=ans;
                                    }
cout<<f<<endl;
}

int main() {
    solve();
    return 0;
}