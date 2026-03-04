#include <bits/stdc++.h>
#define ll long long
#define str string
#define cout(x) cout << x << "\n"
using namespace std;
void solve(){
    int n, k, tries = 0, max = 0,location = 0;
    cin >> n >> k;
    vector<int> arr;
    for(int i = 0; i < k; i ++){
        int x;
        cin >> x;
        arr.push_back(x);
        if(x >= max){
            max = x;
            location = i;
        }
    }
    for(int i = 0; i < arr.size(); i ++){
        while(arr[i] > 1 && i != location){
            arr[i] --;
            tries += 2;
        }
    }
    tries += (arr.size()-1);
    cout(tries);
 
 
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
 
}