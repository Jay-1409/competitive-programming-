#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int test=0;test<t;test++){
        int a,b;
        cin >> a >> b;
        if((a+b)%2==0){
            cout <<"Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
}