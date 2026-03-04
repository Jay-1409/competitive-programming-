#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int index(int arr[],int x,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return i;
        }
    }
}

void solve() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<index(arr,i+1,n)+1<< " ";
    }
}

int main() {
    solve();
    return 0;
}