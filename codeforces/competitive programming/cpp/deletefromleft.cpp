#include<iostream>
using namespace std;
int main(){
    string s1; cin >> s1;
    string s2; cin >> s2;
    int count=0;
    for(int i=s1.length()-1,j=s2.length()-1;i>=0&&j>=0;i--,j--){
        if(s1[i]==s2[j]){
            count++;
        } else{
            break;
        }
    }
    cout << (s1.length()-count)+(s2.length()-count)<< endl;
    return 0;   
}