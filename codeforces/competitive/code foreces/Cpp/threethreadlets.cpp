#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
    void arrSort(int arr[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void solve() {
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b&&b==c){
        cout<<"YES" << endl;
        return;
    }
    
    int arr[3]={a,b,c};
    arrSort(arr,3);
    vector<int> od;
    for(int i=0;i<3;i++){
        if(arr[0]%2!=0){
            od.push_back(arr[0]);
        }
    }
    // for(int i=0;i<od.size();i++){
    //     if(od[i]>=5){
    //         cout<<"NO"<< endl; return;
    //     }
    // }
    int ans=((arr[2]/arr[0])-1)+((arr[1]/arr[0])-1);
    if((arr[1]%arr[0]==0&&arr[2]%arr[0]==0)&&ans<=3){
        cout<<"YES"<< endl;
    } else{
        cout<< "NO" << endl;
    }
    // if(a%2!=0&&b%2!=0){
    //     if(a>3||b>3){
    //         cout<<"NO"<< endl;
    //         return;
    //     }
    // } else {
    //     cout<<"YES" << endl;
    // }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}