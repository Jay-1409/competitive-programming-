class Solution {
public:
    int numTilePossibilities(string tiles) {
        set<string> st;
        auto apply_perm = [&](string &x) -> void {
            sort(x.begin(), x.end());
            do {
                st.insert(x);
            } while(next_permutation(x.begin(), x.end())); 
        };
        auto dfs = [&](int loc, string cur, auto && self) -> void {
            if(loc >= (int)tiles.size()) {
                if(!cur.empty()){
                    apply_perm(cur);
                }
                return;
            }
            self(loc + 1, cur + tiles[loc], self);
            self(loc + 1, cur, self);
        };
        dfs(0, "", dfs);
        vector<string> ans(st.begin(), st.end());
        for(auto &I : ans ) {
            cout << I << endl;
        }
        return (int)ans.size();
    }
};