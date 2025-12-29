class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto &I : edges) {
            adj[I[0]].push_back(I[1]);
            adj[I[1]].push_back(I[0]);
        }
        vector<int> ans(n, 0);
        auto dfs = [&](int node, int par, auto &&self) -> vector<int> {
            vector<int> color(26, 0);
            color[labels[node] - 'a']++;
            for(auto &i : adj[node]) {
                if(i != par) {
                    vector<int> res = self(i, node, self);
                    for(int j = 0; j < 26; ++j) {
                        color[j] += res[j];
                    }
                }
            }
            ans[node] = color[labels[node] - 'a'];
            return color;
        };
        vector<int> res = dfs(0, -1, dfs);
        return ans;
    }
};