#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int a=0,b=0,c=0;
    char x;
    for(int i=0;i<9;i++){
        cin>>x; if((int)x==65){a++;}
        else if((int)x==66){b++;}
        else if((int)x==67){c++;}
    }
    if(a!=3){
        cout<<'A'<<endl;
    }else if(b!=3){
        cout<<'B'<<endl;
    }else{
        cout<<'C'<<endl;
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