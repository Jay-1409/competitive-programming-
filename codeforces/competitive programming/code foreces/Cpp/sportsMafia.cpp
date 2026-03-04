#include<iostream>
#include<cmath>

using namespace std;
int main(){
    int n,k;
    cin >> n;//moves
    cin >> k;//candies left
    //eat one candy
    //put one more candy than last time 
    int ate=0;
    int sum=0;
    int j=1;
    for(int i=0;i<n;i++){
        if(sum==0){
            sum++;
            continue;
        }
        if(k==n){
            ate=0; break;
        }
        if(n>=k){
                sum=sum+j;
                j++;
            if(sum>=ceil(n/2)){
                sum--;
                ate++;
            }
        }
        if(k>n){
            sum=sum + j;
            j++;
            if(j>=ceil(k/2)){
                sum--;
                ate++;
            }
        }
    }
    if(n==k && n==1){
        cout << ate << endl;
    }else {
    cout << ate-1 << endl;
    }
}

