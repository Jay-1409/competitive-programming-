class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n + 1);
        for(auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<double> cnt(n + 1, 0);
        auto dfs = [&](int node, int par, double running_probab, int time, auto && self) -> void {
            if(t == time) {
                // cout << node << endl;
                cnt[node] = running_probab;
                return;
            }
            bool went_to_child = false;
            int deg = adj[node].size() - (par == -1 ? 0 : 1);
            for(auto &i : adj[node]) {
                if(i != par) {
                    self(i, node, running_probab * (1/(double)deg), time + 1, self);
                    went_to_child = true;
                }
            }
            if(!went_to_child && time < t) {
                self(node, par, running_probab, time + 1, self);
            }
        };
        dfs(1, -1, 1.0, 0, dfs);
        return cnt[target];
    }
};