#include<iostream>
using namespace std;
int Cunique(int arr[],int size){
    int count=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
    }
    return count;
}
int main(){
    int t;
    cin >> t;
    for(int times=0;times<t;times++){
    int size;//size of purmutation
    cin >> size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    for(int i=0;i<size-2;i++){
        if(arr[i+1]>arr[i] && arr[i+1]>arr[i+2]){
            if(arr[i]<arr[i+2]){
//swap arr[i+1] and arr[i+2]
                int temp=arr[i+2];
                arr[i+2]=arr[i+1];
                arr[i+1]=temp;
            }
            if(arr[i]>arr[i+2]){
//swap arr[i+1] and arr[i]
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        }
            int count=0;
                for(int k=0;k<=size-2;k++){
                    if(arr[k]<arr[k+1]){
                        // cout << arr[k] << endl;
                        // cout << arr[k+1] << endl;
                        count++;
                        //cout << "k:" << k << endl;
                        // cout<<count<<endl;  
                    }
                }
            if(count+1==size){
                cout << "YES" << endl;
                continue;
            }
int test=Cunique(arr,size);
            if(test>0){
                cout<<"NO"<< endl;
                continue;
            }
            else{cout << "NO" << endl;continue;}
    }
}