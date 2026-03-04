#include<iostream>
using namespace std;
int main(){
    int n,m;
    //m-number of pages per page
    //n-number of days in total
    cin >> n; cin >> m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
int pages[n];
    int sum=0;
    int x=0;
    int y=5;
    for(int i=0;i<n;i++){
    int page=0;

        sum=sum+arr[i];
        for(int j=0;j<100;j++){
            x=x+5;
            if(sum>=x){
                page++;
                // cout << sum;
                // cout << page;
                // cout << "test" << endl;
                
            }
        }
        // cout << page;
        pages[i]=page;
    }
    for(int i=0;i<n;i++){
        cout << pages[i] <<" ";
    }
    return 0;
}