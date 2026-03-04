#include<iostream>
using namespace std;
int main(){
    int n,count=0;
    cout << "Enter the number of fishes in the pond: ";
    cin >> n;
    cout << "enter the fish no.: " << endl;
    int river[n];
    for(int i=0;i<n;i++){
        cin >> river[i];
    }
    for(int i=0;i<n;i++){
        if(river[i]>river[i+1]){
            count++;
            cout << "Surviver: " << river[i] << endl;
        }
    }
    cout << "number of fish remaining are: " << count;
}