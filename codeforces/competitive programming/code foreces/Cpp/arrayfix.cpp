#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int getSumDigits(int no)
{
    int sum = 0;

    while (no)
    {
        sum += no % 10;
        no /= 10;
    }

    return sum;
}
void solve() {
    int n; cin>>n;
    vector<int> v;
    vector<int> f;
    int x;
    for(int i=0;i<n;i++){
        cin>>x; v.push_back(x);
    }
    int i;
    for(i=0;i<n-1;i++){
        if(v[i]>v[i+1]){
            f.push_back(v[i]/10);
            f.push_back(v[i]%10);
        }else{
            f.push_back(v[i]);
        }
    }
    
    if(f.back()>v[n-1]){
        f.push_back(v[n-1]/10);
        f.push_back(v[n-1]%10);
    } else{
        f.push_back(v[n-1]);
    }
    for(int i=0;i<f.size();i++){
        cout<<f[i]<<endl;
    }
    cout<<(is_sorted(f.begin(),f.end())?"YES":"NO")<<endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}