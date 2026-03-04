#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n ; i++){
        cin >> v[i];
    }

    int sum = 0;
    int maxsum = -1e9;

    for(auto i : v){
        sum += i;
        maxsum = max(maxsum,sum);

        if(sum < 0){
            sum = 0;
        }
    }
    cout << maxsum << endl;
}
#undef int
int main(){
int t = 1;
while(t--)solve();
return 0;
}