#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n,m;
    cin>>n>>m;
    char a[n][m];
    int fx,fy,sx,sy,lx,ly;
    int cnt=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='*'){
                if(cnt==1){
                    fx=i;fy=j;
                    cnt++;
                } else if(cnt==2){
                    sx=i;sy=j;
                    cnt++;
                } else if(cnt==3){
                    lx=i;ly=j;
                    cnt++;
                }
            }
        }
    }
    // cout<<fx<<fy<<endl;
    //     cout<<sx<<sy<<endl;
    // cout<<lx<<ly<<endl;
        int ansx,ansy;
        if(fx==sx && fy==ly){
            ansx=lx;
            ansy=sy;
            // cout<<"in 1"<<endl;
        } else if(fx==sx && sy==ly){
            ansx=lx;
            ansy=fy; 
            // cout<<"in 1"<<endl;         
        }
        else if(sx==lx && ly==fy){
            ansx=fx;
            ansy=sy;
            // cout<<"in 2"<<endl;
        } else if(sx==lx && sy==fy){
            ansx=fx;
            ansy=ly;                
        } 
        cout<<ansx+1<<" "<<ansy+1<<endl;
}

int main() {

        solve();
    return 0;
}