#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0 ;i < n ; i ++){
        cin >> v[i];
    }
    sort(v.rbegin(),v.rend());
    int val = 0;
    int sum = accumulate(v.begin(),v.end(),0);
    int cnt = 0;
    for(auto i : v){
        val += i;
        cnt++;
        sum -= i;
        if(val > sum){
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}