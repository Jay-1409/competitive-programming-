#include<iostream>
using namespace std;
int main(){
    int w;
    cin >> w;
    if(w%2==0){
        if(w==2){
        cout << "No";
    } 
    else{
        cout << "Yes";}
    }
    else if(w%2!=0){
        cout << "No";
    }

}