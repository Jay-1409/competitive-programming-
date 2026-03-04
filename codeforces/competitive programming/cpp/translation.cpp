#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    string a;
    string b;
    cin>>a>>b;
    reverse(b.begin(),b.end());
    int flg=0;
    for(int i=0;i<b.length();i++){
        // cout<<a[i]<<" "<<b[i]<<endl;
        if(a[i]!=b[i]){
            flg++; break;
        }
    }
    if(flg==0){ 
        cout<<"YES"<<endl;
    } else{
        cout<<"NO"<<endl;
    }
}