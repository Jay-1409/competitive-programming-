#include<iostream>
using namespace std;
void solve(){
    int n;cin >> n;
    int arr[n];
    int s1=0;
    int s2=0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            s1++;
        } else if(arr[i]==2){
            s2--;
        } else if(arr[i]==3){
            s1++;
        }
    }
    cout << s1 << endl;
}
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
}