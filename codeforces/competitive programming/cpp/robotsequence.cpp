#include<bits/stdc++.h>
using namespace std;
int val(char c){
	if(c=='U')
		return 1;

	if(c=='D')
		return -1;

	if(c=='R')
		return 1;

	if(c=='L')
		return -1;
	return 0;
}
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int x = 0, y = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        y = 0;
        x = y;
        if(s[i] == 'U' || s[i] == 'D'){
            x = val(s[i]);
        }else{
            y = val(s[i]);
        }
        for(int j = i + 1;j < n ; j ++){
            if(s[j] == 'U' || s[j] == 'D'){
                x+=val(s[j]);
            }else{
                y+=val(s[j]);
            }
            if(x == 0 && y == 0){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}