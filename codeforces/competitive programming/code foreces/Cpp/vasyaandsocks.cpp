#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin >> n; cin >> m;
    int count=0;
    for(int i=1;i<=n;i++){
        if(i%m==0){
            count++;
        if((n+count)%m==0){
            count++;
        }
        }

    }
    cout << n+count<< endl;
    return 0;
}