#include<iostream>
using namespace std;
int test(int i, int j, int k) {
  return std::min(i, std::min(j, k));
}
int main(){
    int n,k,l,c,d,p,nl,np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    // cout << k;
    int x=(k*l)/nl;
    int y=(c*d);
    int z=(p)/np;
    cout << test(x,y,z)/n;
}