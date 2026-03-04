#include<iostream>
using namespace std;
template <typename T, size_t N>

int totalPermutations(int arr[]){
    int size=array_size(arr);
    int total=1;
    for(int i=0;i<size;i++){
        total=total*i;
    }
    return total;
}
int main(){
    int arr[]={1,2,3};
    cout << "The total number of possible permutations are: " << totalPermutations << endl;
    
}