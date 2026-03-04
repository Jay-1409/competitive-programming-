#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    int x;

    map<string,int> m;
    for(int i=0;i<n;i++){
        cin>>s;
        cin>>x;
        m.insert({{s,x}});
    }
    map<string,int> :: iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<(*it).first<< " "<<(*it).second<<endl;
    }

}