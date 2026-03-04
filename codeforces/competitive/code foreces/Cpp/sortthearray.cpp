#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i ++){
        cin >> v[i];
    }
    if(is_sorted(v.begin(),v.end())){
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
        return;
    }
    int l = 0;
    int r = 0;
    bool start = false;
    while(l < n - 1){
        if(v[l] > v[l + 1]){
            r = l;
            start = true;
        }
        if(start){
            while(l < n - 1 && v[l] > v[l + 1]){
                l++;
            }
            break;
        }
        l++;
    }
    reverse(v.begin() + r , v.begin() + l + 1);
    if(is_sorted(v.begin(),v.end())){
        cout << "yes" << endl;
        cout << r + 1 <<" " << l + 1;
    }else{
        cout << "no" << endl;
    }
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}