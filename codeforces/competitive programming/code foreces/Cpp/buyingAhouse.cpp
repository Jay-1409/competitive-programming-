#include<iostream>
using namespace std;
int dist(int arr[],int n,int m,int x){
    int index=0;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            index=i;
            break;
        }
    }
    int dist=0;
    if(m>index){
    dist=m-index;
    }else{
        dist=index-m;
    }
    return dist*10;
}
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

    int arrOut(int *arr, int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }

int main(){
    // house 1 .. house 2 .. house 3 .. ...
    int n;cin >>n;//Number of houses in the villag
    int m;cin >>m;//house of girl 
    int k;cin >>k;//Money

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    arr[m-1]=-1;
    int index=0;

int arro[n];
    for(int i=0;i<n;i++){
        arro[i]=arr[i];
    }
    arrSort(arr,n);
    int min=0;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            min=arr[i];
            break;
        }
    }
        arrOut(arro,n);

    // cout << min;
    // cout << dist(arro,n,m,min);
    for(int i=0;i<n;i++){
    if(arro[i]>0){
        if(arro[i]<=k){
            if(dist(arro,n,m-1,arro[i]) <= dist(arro,n,m-1,min)){
                min=arro[i];
                // cout << i << endl;
            }
        }
    }
    }
    // cout << dist(arro,n,m-1,arro[2]) <<  dist(arro,n,m-1,arro[8]) << endl;
    // cout << min << endl;
    cout << dist(arro,n,m-1,min) << endl;
}