
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin>>n;
    double arr[n];
        double ans=0.0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        ans+=arr[i];
    }
    cout<<ans/(double)n<<endl;
}

int main() {
        solve();    
    return 0;
}