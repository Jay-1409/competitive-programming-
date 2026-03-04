
#include<iostream>
#include<vector>
using namespace std;
int sum(int n){
    int sum=0;
    int m;
    while(n>0)    
    {    
    m=n%10;    
    sum=sum+m;    
    n=n/10;    
    }
return sum;
}
void solve(){
     int n;
    cin >>n;
        int temp=0;    
    vector< int> v;
    for( int i=0;i<n;i++){
        temp=i+1;
        if(temp>9){
            temp=sum(temp);
        }
        v.push_back(temp);
    }
 int sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
    }
    cout << sum << endl;
    return;
}
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
    return 0;
}