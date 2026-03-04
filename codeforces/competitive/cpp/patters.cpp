#include<iostream>
using namespace std;
//RECTANGE
// int main(){
//     char star='*';
//     int n,m;
//     cin>>n>>m;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n-1;j++){
//             cout<<star;
//         }
//         cout<<star<<endl;
//     }
// }

//HOLLOW RECTANGE
// int main(){
//     int row,col;
//     cin >> row >> col;  
//     for(int i=1;i<=row;i++){
//         for(int j=1;j<=col;j++){
//             if(i==1||i==row||j==1||j==col){
//                 cout << "*"; 
//             }
//             else{
//                 cout << " ";
//             }
//         }
//         cout<<endl;
//     }
// }

//BUTTERFLY PATTERN
int main(){
    int bredth,length;
    cin >> bredth >> length;
    for(int i=1;i<=bredth;i++){
        for(int j=1;j<=9;i++){
            cout << "*";
        }
    }
}
