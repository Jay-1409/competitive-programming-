#include<iostream>
using namespace std;
int main(){
    int testcases;
    cin >> testcases;
    for(int t=0;t<testcases;t++){
    int x,y,k,sec=0,stam=0;
    cin >> x >> y >> k;
    //x=chest
    //y=key
    //k=stamina, stam=stamina count;
    int n=0; //location of monocarp
    if(x>y){
        int distchest=x-n;
        cout << distchest << endl;
    }
    else if(y>x){
        int distchest=x-n;
        int distChest_Key=y-x;
        int indirect,direct;
        for(x;x<y;x++){
            stam++;
            if(stam>k){
                break;
            }   
        }
            // else{
            //     cout << "2";
            // direct=(sec+distchest-1);
            // }
        if(stam>k){cout << distchest+2*(distChest_Key-stam)+4 << endl;}
        else if(stam<=k){cout << sec+distchest+2 << endl;}

    }
    else if(x==y){
        cout << y-n;
    }
}
}