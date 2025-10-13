class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : connections) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, 1}); // original direction (u -> v), needs change if we go this way
            adj[v].push_back({u, 0}); // reverse direction (v -> u), already good
        }
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int ans = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &[v, cost] : adj[u]) {
                if (!vis[v]) {
                    ans += cost;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};
