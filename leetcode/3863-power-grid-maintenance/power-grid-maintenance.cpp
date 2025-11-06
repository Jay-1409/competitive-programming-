class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // reduce to components 
        // now for each component we find the smallest -> one set per grid node in that component
        // solve queries accordingly
        vector<vector<int>> adj(c + 1);
        for(auto &i : connections) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<set<int>> st;
        map<int,int> mp;
        vector<int> vis(c + 1, false);
        int code = 0;
        auto dfs = [&](int node, set<int> &trace, int code, auto && self) -> void {
            if(!vis[node]) {
                vis[node] = true;
                mp[node] = code;
                trace.insert(node);
                for(auto &i : adj[node]) {
                    self(i, trace, code, self);
                }
            }  
        };
        for(int i = 1; i <= c; i++) {
            if(!vis[i]){
                set<int> temp;
                dfs(i, temp, code, dfs);
                st.push_back(temp);
                code++;
            }
        }
        vector<bool> active(c + 1, true);
        vector<int> ans;
        for(auto &i : queries){
            int node = i[1];
            int op = i[0];
            if(op == 1) {
                if(active[node]) {
                    ans.push_back(node);
                } else {
                    int cmp = mp[node];
                    if(st[cmp].empty()){
                        ans.push_back(-1);
                        continue;
                    }
                    auto u = *st[cmp].begin();
                    ans.push_back(u);
                }
            } else {
                int cmp = mp[node];
                st[cmp].erase(node);
                active[node] = false;
            }
        }
        return ans;
    }
};