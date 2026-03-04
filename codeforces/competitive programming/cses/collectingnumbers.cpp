#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n; i++)
    cin >> v[i];
    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(v[i] < v[i-1]){
            cnt++;
            swap(v[i], v[i-1]);
        }
    }
    cout << cnt << endl;
}
int main(){
solve();
return 0;
}