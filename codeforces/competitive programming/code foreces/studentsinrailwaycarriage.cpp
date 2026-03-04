#pragma GCC optimize("-finline","-finline-small-functions","O3","-fexpensive-optimizations")
#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,a,b;
    int x,y;
    cin >> n >> x>> y;
    string s; cin >> s;
    if(a<b)swap(a,b);
    bool aa = false;
    int cnt=0;
    for(int i = 0 ; i < 2 ; i ++ ){
        int cnt1=0;
        if(i == 0 )aa=true;
        else aa = false;
        int a = x;
        int b = y;
        if(a > b)swap(a,b);
        for(int i = 0 ; i < n ; i ++ ){
            if(s[i] != '*'){
                if(a>0 && aa){
                    a--;
                    aa = false;
                    cnt1++;
                }else if(b > 0 && !aa){
                    b--;
                    aa = true;
                    cnt1++;
                }else{
                    if(a>b)aa=true;
                    else aa= false;
                }
            }else{
                if(a>b)aa=true;
                else aa = false;
            }
        }
        cnt = max(cnt,cnt1);
    }
    cout << cnt << endl;
}
int main(){
int t = 1;

while(t--)solve();
return 0;

}