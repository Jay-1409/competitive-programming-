#include<iostream>
#include<cmath>
using namespace std;
bool dist(int n,int m,int xk,int yk,int xq,int yq){
    int p=sqrt(pow((n-xk),2)+pow(m-yk,2));
    int q=sqrt(pow((n-xq),2)+pow(m-yq,2));
    if(p==q){
        return true;
    } else {
        return false;
    }
}
void solve(){
    int a,b;
    cin>>a>>b;
    int xk,yk;
    cin>>xk>>yk;
    int xq,yq;
    cin>>xq>>yq;
int cnt=0;
    for(int i=0;i<5;i=i+a){
            if(dist(i,b,xk,yk,xq,yq)){
                cnt++;
            }
            // if(dist(b,i,xk,yk,xq,yq)){
            //     cnt++;
            // }
    }

    cout<< cnt<< endl;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        solve();
        t--;
    }
}