#include<iostream>
using namespace std;
int count(char arr[4][4],int x){
    int count=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if((int)arr[i][j]==x){
                count++;
            }
        }
    } return count ;
}
int main(){
    int k;cin>> k;int flag=1;
    char arr[4][4];int max=0;int min=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> arr[i][j];
            if((int)arr[i][j]>max){
                max=(int)arr[i][j];
            }
            if((int)arr[i][j]<min){
                min=(int)arr[i][j];
            }
        }
    min=arr[0][0];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if((int)arr[i][j]>max){
                max=(int)arr[i][j];
            }
            if((int)arr[i][j]<min){
                min=(int)arr[i][j];
            }
        }
    }
    
    } int z=0;
    for(int i=min;i<=max;i++){
        if(i==46){
            continue;
        }
        
        int a=count(arr,i);
        if(a<=2*k){
            flag=1;
        } else if(a>2*k){
            flag=0; break;
        }
    }
    if(flag==1){
        cout << "YES" << endl;
    } else if(flag==0){
        cout << "NO" << endl;
    }
}