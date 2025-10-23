class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> adj(n);
        for(auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        unordered_map<int,unordered_map<bool,long long>> cache;
        auto dfs = [&](int node, int par, bool not_taken, auto && self) -> long long {
            bool isLeaf = (adj[node].size() == 1 && par != -1);
            if(cache.count(node) && cache[node].count(not_taken))
                return cache[node][not_taken];
            long long take_cur = values[node];
            long long not_take_cur= 0;
            for(auto &child : adj[node]) {
                if(child == par)
                    continue;
                // cout << node << " " << child << endl;
                take_cur += self(child, node, not_taken, self);
                if(!not_taken)
                    not_take_cur += self(child, node, true, self);
            }
            if(isLeaf) {
                // cout << node << ":" << not_taken << " " << values[node] << endl;
                return cache[node][not_taken] = (not_taken * values[node]);
            }
            // cout << node << " " << not_taken << " " << values[node] << endl;
            return cache[node][not_taken] = max(take_cur , not_take_cur);
        };
        return dfs(0, -1, false, dfs);
    }
};