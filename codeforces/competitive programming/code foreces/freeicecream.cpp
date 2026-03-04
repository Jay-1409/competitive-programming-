#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long t,n;
    cin >> t >> n;
    int dis = 0;
    while(t--){
        char c; 
        cin >> c;
        long long d;
        cin >> d;
       if(c == '+'){
        n += d;
       }else{
        if(n - d >=0 ){
            n -= d;
        }else{
            dis++;
        }
       }
    }
    cout << n << " " << dis << endl;
}
int main(){
int t = 1; 

while(t--)solve();
return 0;
}