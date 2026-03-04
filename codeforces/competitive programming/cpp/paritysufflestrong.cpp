#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    if(is_sorted(a.begin(),a.end())){
        cout << 0 << endl;
        return;
    }
    if(a[0]&1==a[n-1]&1){
        a[0]=a[n-1];
    }    
    else{
        a[n-1]=a[0];
    }
    int l = 0;
    int c = 0;
    int r = 0;
    cout << n - 1 << endl;
    cout << 1<<" "<<n<<endl;
    for (int i = 1; i < n; i++)
    {   
        if((a[0]+a[i])&1){
            cout << 1<<" "<<i+1<<endl;
        }
        else{
            if(i==n-1) continue;
            cout <<i+ 1<<" "<<n<<endl;
        }
    }
}

#undef int
int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
