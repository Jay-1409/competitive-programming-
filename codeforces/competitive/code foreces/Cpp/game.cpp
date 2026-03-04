#include<iostream>
using namespace std;
bool checkAdjacent(int a,int b){
    if(a==b){
        if(a==0){
            return false;
        }

        return true;
    }
    return false;
}
int main(){
    int t;
    cin >> t;
    for(int test=0;test<t;test++){
        int n;
        int coins=0;
        cin >> n;
        int arr[n];        
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        for(int i=0;i<n-1;i++){
            if(!checkAdjacent(arr[i],arr[i+1])){
                coins++;
            }
        }
        cout << coins << endl;
    }
}