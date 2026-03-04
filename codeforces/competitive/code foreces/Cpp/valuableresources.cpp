#include<bits/stdc++.h>
using namespace std;
//SOLVED
void solve(){
    long long n;
    cin >> n;
    long long maxx= -1e9;
    long long minx = 1e9;
    long long miny = 1e9;
    long long maxy = -1e9;
    while(n--){
        long long x,y;
        cin >> x >> y;
        maxx = max(maxx,x);
        minx = min(minx,x);
        miny = min(miny,y);
        maxy = max(maxy,y);
    }
    cout << max((maxx - minx)*(maxx-minx) , (maxy - miny)*(maxy - miny)) << endl;
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}