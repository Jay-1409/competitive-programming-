#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int xdiva(long long int a, long long int x){
    return x/a;
}
long long int xmoda(long long int a,long long int x){
    return x%a;
}
void solve() {
    long long int l;
    long long int r;
    long long int a;

    cin>>l>>r>>a;
    
    long long int max=0;
    // for(int i=l;i<=r;i++){
    //     long long ans=xdiva(a,i)+xmoda(a,i);
    //     if(ans>max){
    //         max=ans;
    //     }
    // }
    
    cout<<max<<endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}