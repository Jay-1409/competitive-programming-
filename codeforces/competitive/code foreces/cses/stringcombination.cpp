#include<bits/stdc++.h>
using namespace std;
map<string,bool>mp;
void level(string og, int l, int r, vector<string> &ans) {
    if (l == r && mp[og] == false) {
        ans.push_back(og);
        mp[og] = true;
    } else {
        for (int i = l; i < r; i++) {
            swap(og[l], og[i]);  
            level(og, l + 1, r, ans);  
            swap(og[l], og[i]); 
        }
    }
}

int main() {
    string s;
    cin >> s;
    vector<string> ans;
    level(s, 0, s.length(), ans);
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
