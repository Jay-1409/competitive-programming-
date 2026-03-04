#include<iostream>
using namespace std;
int main(){
    int n; int a=0,b=0;
    cin >> n;
    char s[n];
    for(int i=0;i<n;i++){
        cin >> s[n];
        if(s[n]=='A'){
            a++;
        }
        else if(s[n]=='D'){
            b++;
        }
    }
    if(a>b){
        cout << "Anton" << endl;
    } else if(b>a){
        cout << "Danik" << endl;
    } else if(a==b){
        cout << "Friendship" << endl;
    }
    return 0;
}