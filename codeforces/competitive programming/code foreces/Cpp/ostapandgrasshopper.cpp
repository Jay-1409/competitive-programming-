#include<iostream>
#include<string>
using namespace std;
int main(){
    int n,k; int t,g; int o=0; 
    cin>>n;
    cin>>k;
    unsigned char arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]=='T'){
            t=i;
        }
        if(arr[i]=='G'){
            g=i;
        }
        if(arr[i]=='#'){
            o++;
        }
    }
    int dist=abs(g-t);
    if(dist<k||dist%k!=0){
        cout<<"NO"<< endl;
        return 0;
    }
    if(g<t){
        int flag=0;
        for(int i=0;flag<=t;i++){
            if(arr[g+(i*k)]=='T'){
                cout <<"YES"<< endl; break;
            }
            else if(arr[g+(i*k)]=='#'){
                cout << "NO" << endl; 
                break;
            } 
        }
    } else if(t<g){
        int flag=0;
        for(int i=0;flag<=g;i++){
            if(arr[t+(i*k)]=='G'){
                cout <<"YES"<< endl; break;
             }   
            else if(arr[t+i*k]=='#'){
                cout << "NO" << endl; 
                break;
             } 
        }
    }
}