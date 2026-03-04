#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#ifndef ONLINE_JUDGE
#endif
int sumtil(vector<long> v,long  p){
    int sum=0;
    for(int i=0;i<p;i++){
        sum+=v[i];
    }
    return sum;
}
int sumafter(vector<int> v,int p){
    int sum=0;
    for(int i=p;i<v.size();i++){
        sum+=v[i];
    }
    return sum;
}
void solve() {
    long int n;
    cin>>n;
    vector<long long> v;
    int x; int flag=0;int flag2=0;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        v.push_back(x);
        if(x!=1){
            flag=1;
        }
        if(x!=0){
            flag2=1;
        }
    }
    if(flag==0){
        printf("%d\n",0);return;
        // cout<<0<< "\n";return;
    }
    if(flag2==0){     
        printf("%d\n",n-1);return;
        // cout<<n-1<< "\n";return;
    }
    int ans=0;
    int s=1;
    for(int i=0;s<v.size();i++){
        if(sumtil(v,s)==sumafter(v,s)){
            ans++;
        }
        s++;
    }
    cout<<ans<<"\n";
}

int main() {
    solve();
    return 0;
}
