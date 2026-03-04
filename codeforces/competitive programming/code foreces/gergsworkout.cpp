#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin>>n;
    int arr[3]={0};
    int flg=1;
    int x=0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(flg==1){
            arr[0]+=x;
            flg=2;
        }
        else if(flg==2){
            arr[1]+=x;
            flg=3;
        }
        else if(flg==3){
            arr[2]+=x;
            flg=1;
        }
    }
    int maxi=0;
    int maxv=arr[0];
    for(int i=0;i<3;i++){
        // cout<<arr[i]<<maxv<<endl;
        if(arr[i]>maxv){
            maxi=i;
            maxv=arr[i];
        }
    }
    if(maxi==0){
        cout<<"chest"<<endl;
    }else if(maxi==1){
        cout<<"biceps"<<endl;
    }else if(maxi==2){
        cout<<"back"<<endl;
    }
}

int main() {
        solve();
    return 0;
}