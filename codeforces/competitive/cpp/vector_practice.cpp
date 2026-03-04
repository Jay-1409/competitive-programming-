#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int countK(vector<int>v,int k){
    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==k){
            count++;
        }
    } return count;
}
bool checkAdj(int a,int b,int k){
    if(a==b && a==k){
        return true;
    } return false;
}
int main(){
    int t;
    cin >> t;
    for(int test=0;test<t;test++){
        vector<int> v;
        int n,k;
        cin >> n >> k;
        for(int i=0;i<2*n;i++){
            int x=0;
            cin >> x;
            v.push_back(x);
        }
        int flag=0;
        int count=countK(v,k);
        for(int i=0;i<=n-2;i=i+2){
            if(checkAdj(v[i],v[i+1],k)){
                flag++;
                break;
            }
        }
        if(count > ceil(n/2)){
            flag++;
        }
        cout << count << endl;
        cout << flag << endl;
        if(flag>0){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
}