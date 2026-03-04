#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
int main(){
    int a=1;
    int b=2;
    int *pa=&a;
    int *pb=&b;
    swap(pa,pb);
    cout << a << " " << b ;
    
}

