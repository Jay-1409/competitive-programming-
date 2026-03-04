#include<bits/stdc++.h>
using namespace std;
double level(double n,double x, double ans){
    if(n <= 0){
        return ans;
    }
    return level(n-1,x,ans*x);
}
double mission(double n,double x, double ans){
    if(n <= 0){
        return ans;
    }
    cout << ans << endl;
    return mission(n-1,x,ans/x);
}
int main(){
    double n,x;
    cin >> n >> x;
    swap(n,x);
    if(x > 0){
        cout << floor(level(n,x,(double)1)) << endl;
    }else if(n == 0){
        cout << 1 << endl;
    }else{
        x = abs(x);
        cout << floor(mission(n,x,n)) << endl;
    }
}