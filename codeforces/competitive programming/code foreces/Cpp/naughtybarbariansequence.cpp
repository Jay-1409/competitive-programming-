#include<iostream>
using namespace std;
bool satisfy(int a,int i){
    if(a<=i){
        return true;
    }else{
        return false;
    }
}

    int arrOut(int arr[], int size) {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
    }
void InsertItem(int arr[],int n, int index, int val)
{  
    n++;
    // arr[n+1]=0;
  for(int i=index;i<n-1;i++)
  {
    int x=arr[i+1];
    arr[i+1] = arr[i];
    arr[i+2] = x;
  }
  arr[index] = val;

}

int main(){
    int t;
    cin >>t;
    for(int test=0;test<t;test++){
        int n;
        cin >> n;
        int arr[n];
        for(int i=1;i<=n;i++){
            cin >> arr[i];
        }
        int arr1[100000];
        int count=0;
        for(int i=1;i<=n;i++){
            if(!satisfy(arr[i],i)){
                InsertItem(arr,n,i,i);
                n=n+1;i++;
                count++;
            }
            arrOut(arr,n);
            cout << endl;
        }
        cout << count << endl;
    }
}