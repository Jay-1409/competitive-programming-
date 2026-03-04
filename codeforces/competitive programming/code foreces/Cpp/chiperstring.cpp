#include<iostream>
using namespace std;
int main(){
    string s;int flag=0;
    getline(cin, s);
    cout << s[(s.size()/2)-1];
    for(int i=0;i<s.size()-1;i++){
        if(flag==0){
            cout << s[s.size()-i];
            flag=1;
        } else{
            cout << s[i];
            flag=0;
        }
    }

}