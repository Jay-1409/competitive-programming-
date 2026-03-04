#include<bits/stdc++.h>
using namespace std;
void solve(){
    vector<string> v;
    int t = 4;
    int min = 1e9;
    int id = 0;
    vector<int> len;
    while(t--){
        string s;
        cin >> s;
        v.push_back(s);
        if(s.length() < min){
            min = s.length();
        }
        len.push_back(s.length());
    }
    for(int i = 0 ; i < len.size() ; i++){
        if(len[i]/2 > min && i != id){
            cout << "C" << endl;
            return;
        }
    }
    if(id == 0){cout << "A" << endl;}
    else if(id == 1){
        cout << "B" << endl;
    }else if(id == 2){
        cout << "C" << endl;
    }else{
        cout << "D" << endl;
    }
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}