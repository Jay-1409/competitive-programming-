#include<iostream>
using namespace std;
void Pyramid_1_0(int n);
void Rhombus(int n);
void NumberPyramid(int x);
void PalindromicTriangle(int x);
int main(){
    int n;
    cin >> n;
    Pyramid_1_0(n);
    Rhombus(n);
    NumberPyramid(n);
    PalindromicTriangle(n);
    }
void PalindromicTriangle(int x){
    int n=x+1;
    for(int i=0;i<n;i++){
        for(int j=n-i;j>1;j--){
            cout << " ";
        }
        for(int k=i;k>0;k--){
            cout << k;
        }
        for(int l=2;l<=i;l++){
            cout << l;
        }
        cout <<endl;
    }
}
void NumberPyramid(int x){
    int n=x+1;
    for(int i=0;i<n;i++){
        for(int j=n-i;j>1;j--){
            cout << " ";
        }
        for(int k=1;k<=i;k++){
            cout << k;
            cout<<" ";
        }
        cout << endl;
    }
}
void Pyramid_1_0(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<i;j++){
            if((i+j)%2==0){
                cout << "0";
                }
            else if((i+j)%2!=0){
                cout << "1";
            }
        }
        cout << endl;
    }
}
void Rhombus(int n){
    for(int i=0;i<n;i++){
        for(int j=n;j>i;j--){
            cout << "  ";
        }
        for(int k=0;k<n;k++){
            cout << "*";
        }
    cout << endl;
    }
}