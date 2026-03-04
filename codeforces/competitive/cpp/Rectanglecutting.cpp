#include<iostream>
using namespace std;
int main(){
    int t;
	cin>>t;
    for (int x=0 ;x < t; x++) { 
        int i,j;cin>> i>>j;
        if (i%2==0 || j%2==0){
            if(j%2==0 && i%2==0){
				cout <<"YES" << endl;
            }
            else if (j==2*i || i==j*2){
            	cout << "NO" << endl;
            }else{
            	cout << "YES" << endl;
            }
        }else{
			cout << "NO" << endl;
        }
    }
}

