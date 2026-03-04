#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int noM(int d,int k){
    int cnt=0;
    for(int i=1;i<=d;i++){
        if(i%k==0){
            cnt++;
        }
    }
    return cnt;
}
void solve() {
    int d;
    // int k,l,m,n,d;
    int arr[4];
    int minEven=10;
    int minOdd=9;
    int minF=10;int flg=0;
    for(int i=0;i<5;i++){
        cin>>arr[i];
        if(arr[i]==1){
            flg=1;            continue;

        }
        if(arr[i]%2==0&&arr[i]%5!=0){
            if(arr[i]<minEven) minEven=arr[i];
        } else if(arr[i]%3==0&&arr[i]%2!=0){
            if(arr[i]<minOdd) minOdd=arr[i];
        } else if((arr[i]%5==0&&arr[i]%2!=0)&&arr[i]%3!=0){
            // cout<<arr[i]<<endl;
            if(arr[i]<minF) minF==arr[i];
        }
    } cin>>d;
    if(flg==1){
        cout<<d<<endl;return;
    }
    // cin>>k>>l>>m>>n>>d
    int ans=0;
    // for(int i=0;i<4;i++){
    //     ans+=noM(d,arr[i]);
    // }
    cout<<noM(d,minEven)<<endl;
    cout<<noM(d,minOdd)<<endl;
    cout<<noM(d,minF)<<endl;
     ans+=noM(d,minEven);
    ans+=noM(d,minOdd);    
    ans+=noM(d,minF);  

    cout<<ans<<endl;
}

int main() {
                                            solve();
    return 0;
}