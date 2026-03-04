#include<bits/stdc++.h>
using namespace std;
void solve(){
    string h; cin >> h;
    string a; cin >> a;
    int n;    cin >> n;
    map<pair<int,char>,int> mp;
    map<pair<int,char>,bool> vis;
    vector<pair<string,pair<int,int>>> p;
    for(int i = 0;i < n;i++){
        int time;
        char ch;
        int id;
        char cr;
        cin >> time >> ch >> id  >> cr;
        if(cr == 'y'){
            mp[{id,ch}]++;
            if(mp[{id,ch}] == 2){
                string name;
                if(ch == 'h') name = h; 
                else name = a;
                if(!vis[{id,ch}]){
                    string name;
                    if(ch == 'h') name = h; 
                    else name = a;
                    p.push_back({name,{id,time}});
                    vis[{id,ch}] = true;
                }
            }
        }else{
            if(!vis[{id,ch}]){
                string name;
                if(ch == 'h') name = h; 
                else name = a;
                p.push_back({name,{id,time}});
                vis[{id,ch}] = true;
            }
        }
    }
    for(auto i : p){
        cout << i.first << " " << i.second.first << " " << i.second.second << endl;
    }
}
int main(){
int t = 1;
while(t--)solve();
return 0;
}