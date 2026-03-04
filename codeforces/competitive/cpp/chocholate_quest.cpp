#include<iostream>
#include<cmath>
using namespace std;
int compute(int chocholate){
    int tentative=ceil(chocholate/3);
    chocholate=chocholate+tentative;
    if(tentative!=0){  
    compute(tentative);
    }
    cout << chocholate << endl;
}
int main(){
    cout << "Enter rupees: ";
    int n;
    cin >> n;
    int chocholate=n;
    cout << "number of chocholate: " << compute(n);
 ;

}