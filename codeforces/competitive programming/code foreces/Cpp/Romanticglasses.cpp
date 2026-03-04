#include<iostream>
#include<vector>
using namespace std;
int oddsum(vector<int> v, int loc){
    int sum=0;
    for(int i=loc;i<v.size();i=i+2){
        sum=sum+v[i];
    }
    return sum;
}
int solve(){
    int n; cin >> n;int flag=0;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x=0; cin >> x;
        v.push_back(x);
    }
    for(int i=0;i<n;i++){
int her=0; int him=0;
        for(int j=i;j<n;j++){
            her = oddsum(v,j);
            him = oddsum(v,j+1);
            cout << her << " "<< him << endl;
            if(her==him){
                cout << "yes" << endl;
                return 0;
            }
        }
    }
    cout << "no" << endl;
    return 0;
}
int main(){
    int t; cin >> t;
    for(int i=0;i<t;i++){
    solve();
    }
}