#include<iostream>
using namespace std;
int count(int sum,int m){
    int x=0;
    int page=0;
    for(int i=0;i<10;i++){
        x=x+m;
            cout << x << endl;
        if(sum>=x){
            page++;
            sum=sum-x;
            cout << sum << endl;
        }
    }
    return page;
}
int countPages(int arr[],int n,int m){
    int sum=0;
    int x=m;
    for(int i=0;i<n;i++){
    int page=0;
        sum=sum+arr[i];
        if(sum>=x){
            page++;
            x=x+m;
        }
        cout << page << " ";
    }
}
int main(){
    int n,m;
    cin >> n; cin >> m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout<<count(10,5);
    // countPages(arr,n,m);
}