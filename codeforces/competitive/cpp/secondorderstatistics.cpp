#include <iostream>
#include <vector>
#include <algorithm>
#include<set>;
using namespace std;
void arrSort(vector<int> arr, int n) {
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
    int n;cin>>n;
    if(n==1){
        cout<<"NO" << endl;
        return;
    }
    vector<int> v;
    int x; int flag=0;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<v.size()-1;i++){
        if(v[i]!=v[i+1]){
            flag=1;
        }
    }
    if(flag==0){
        cout<<"NO"<< endl;return;
    }
    arrSort(v,n);
    set<int> s(v.begin(),v.end());
    vector<int> v2(s.begin(),s.end());
    cout<<v2[1]<< endl;
}
int main() {
        solve();
    return 0;
}