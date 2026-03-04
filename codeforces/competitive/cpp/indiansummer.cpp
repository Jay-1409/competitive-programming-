#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;
bool checkin(vector<string>v,vector<string> u, string x,string y){
    for(int i=0;i<v.size();i++){
        if(v[i]==x&&u[i]==y){
            return true;
        }
    } return false;
}
int main() {
    int n; 
    cin >> n;
    int m=n;
    string a,b;
    int count=0;
    vector<string> s;
    vector<string> s1;
    while (n--){
        cin>>a>>b;
        if(checkin(s,s1,a,b)){
            // cout<<a<<" "<<b<<endl;
            count++;
        } else{
            s.push_back(a);
            s1.push_back(b);
        }                
    }
    // cout<<s.size();
    // cout<<s1.size();
    cout<<m-count<<endl;
    return 0;
}