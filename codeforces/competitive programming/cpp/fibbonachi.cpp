#include<iostream>
using namespace std;
void fib(int n){
    int a=0;
    int b=1;
    cout << a << endl;
    cout << b << endl;
    for(int i=0;i<n;i++){
        cout << a+b << endl;
        int x=a;
        a=b;
        b=x+b;
    }
}
int main(){
    int n;
    cout << "enter a number: ";
    cin >> n;    
    fib(n);
}