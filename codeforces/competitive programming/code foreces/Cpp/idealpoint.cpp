#include<iostream>
#include<vector>
using namespace std;
void solve(){
    int n,zero=0,sign=0;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x=0;
        cin >> x;   
        v.push_back(x); 
        if(x==0){
            zero=1;
        }
        if(x<0){
            sign++;
        }
    }
    if(zero==1){
        cout << 0 << endl;
    } else if(sign%2==0){
        cout << 1 << endl;
        cout << 1 << " " << 0 << endl;
    } else if(sign%2!=0){
        cout << 0 << endl;
    }
}
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
    return 0;
}