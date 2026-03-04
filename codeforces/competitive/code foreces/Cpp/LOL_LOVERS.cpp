#include<string>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    string s;cin >> s;
    string s2=s;
    //pal
    if(n==2){
        if(s[0]!=s[1]){
            cout << 1 << endl;
            return 0;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(s.begin(),s.end());   
    if(s2==s){
        cout << -1 << endl;
        return 0;
    } 
    int flag=0;
    for(int i=0;i<n-2;i++){
        if(s2[i]==s2[i+2]){
            flag=0;
        } else{
            flag=1;
        }
    }
    if(flag==0){
        cout << -1 << endl; return 0;
    }
    cout << 1 << endl;
    return 0;
}