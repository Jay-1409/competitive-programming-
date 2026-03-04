#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    deque<int> a,b;
    for(int i = 0 ; i < n ; i++){int x; cin >> x;if(x>0)a.push_back(x);}
    for(int i = 0 ; i < n ; i++){int x; cin >> x;if(x>0)b.push_back(x);}
    while(a[0]!=b[0]){
        a.push_front(a.back());
        a.pop_back();
    }
    if(a == b){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    //1 2 3 0
    //1 0 2 0 3
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}