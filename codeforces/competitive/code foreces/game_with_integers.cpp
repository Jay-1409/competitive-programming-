#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int f=0;f<t;f++){
    int n;
    int count=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        if(n%3==0){
            cout << "Second" << endl;
            break;
        }

        else if((n+i)%3==0){
            cout << "First" << endl;
            break;
        }
        else if((n-i)%3==0){
            cout << "First" << endl;
            break;
        }
        count++;
        if(count>=10){
            cout << "Second" << endl;
            break;
        }
    }
    }
}