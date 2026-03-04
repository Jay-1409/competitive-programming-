#include<iostream>
using namespace std;

int sumAlternative(int arr[],int n,int x){
    //x=starting loc i.e. 0/ 1
    int sum=0;
    if(x==0){
        
        for(int i=0;i<n;i++){
            if(i%2==0){
                //ie 1 3 5 or even idexes
                sum=sum+arr[i];
            }
            {
                /* code */
            }
            
        }
    }
    if(x==1){
        //starting from the second location ie 1 index
        for(int i=0;i<n;i++){
            if(i%2!=0){
                sum=sum+arr[i];
            }
        }
    }
    return sum;
}
int main(){
    int n;
    int arr1[n];
    int arr2[n];
    for(int i=0;i<n;i++){
        cin >> arr1[i];
    }

    for(int i=0;i<n;i++){
        cin >> arr2[i];
    }

    
}