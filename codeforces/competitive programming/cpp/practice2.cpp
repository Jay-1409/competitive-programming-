#include<iostream>
#include<string>
#include<algorithm>
using namespace std ;
int main(){
    string s;
    getline(cin,s);
    int x=s.size();
    char arr[x];
    for(int i=0;i<s.size();i++){
        arr[i]=s[i];
    }
    for(int i=s.size();i>=0;i--){
        cout << arr[i-1];
    }
}