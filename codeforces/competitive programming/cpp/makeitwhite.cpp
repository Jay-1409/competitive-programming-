#include<iostream>
#include<vector>
using namespace std;
void solve(){
	string s;
	int n; cin >> n;
	cin >> s;
	vector<int> v;
	for(int i=0;i<s.length();i++){
		if(s[i]=='B'){
			v.push_back(i);
		} 
	}
//	cout << v[v.size()-1] << " " << v[0] << endl;
	cout << v[v.size()-1]-v[0]+1 << endl;
}
int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		solve();
	}
}
