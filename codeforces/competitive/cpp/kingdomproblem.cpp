#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s;
    cin >> s;
    vector<int>v1;
    vector<int>v2;
    int flag=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='.'){
            flag=1;
        }
        if(flag==0){
            int x=0;cin >> x;
            v1.push_back(x);
        }
        else if(flag==1){
            int x=0;cin >> x;
            v2.push_back(x);
        }
        
    }
}