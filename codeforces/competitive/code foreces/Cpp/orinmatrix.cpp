#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n , m; 
    cin >> n >> m;
    int arr[n][m];
    int grd[n][m];
    for(int i = 0; i < n ; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            cin >> arr[i][j];
            grd[i][j] = 1;
        }
    }
    for(int i = 0;i < n ; i ++ ){
        for(int j = 0 ; j < m ; j ++){
            if(arr[i][j] == 0){
                int k = 0;
                while(k < n){
                    grd[k][j] = 0;
                    k++;
                }
                k = 0;
                while(k < m){
                    grd[i][k] = 0;
                    k++;
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i ++ ){
        for(int j = 0 ; j < m ; j ++){
            int temp = 0;
            for(int k = 0; k < n; k ++){
                temp = temp | grd[k][j];
            }
            for(int  k = 0; k < m; k ++){
                temp = temp | grd[i][k];
            }
            if(temp != arr[i][j]){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n ; i ++ ){ 
        for(int  j = 0 ; j < m ; j ++){
            cout << grd[i][j] << " ";
        }cout << endl;
    }
    return;
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}