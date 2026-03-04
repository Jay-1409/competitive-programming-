#include<iostream>
using namespace std;

int main(){
    int n,m;int g=0;
    cin >> n >> m;
    char arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
for(int i=0;i<m;i++){
    int max=arr[0][0];int count=0;
    for(int j=0;j<m;j++){
        if(arr[j][i]>max){
            max=arr[j][i];
        }
    }
    for(int j=0;j<m;j++){
        if(arr[j][i]==max){
            count++;
        }
    }
    if(count==1){
        g++;
    }
}   
    cout << g << endl;
}