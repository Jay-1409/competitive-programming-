class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        queue<int> root;
        vector<vector<int>> adj(n);
        vector<int> incomming(n, 0);
        for (auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            incomming[i[1]]++;
        }

        for (int i = 0; i < n; i++) {
            if (incomming[i] == 0) {
                root.push(i);
            }
        }
        vector<set<int>> children(n);
        auto dfs = [&](int node, auto &&self) -> void {
            for (int nxt : adj[node]) {
                bool changed = false;
                if (!children[nxt].count(node)) {
                    children[nxt].insert(node);
                    changed = true;
                }
                for (int a : children[node]) {
                    if (!children[nxt].count(a)) {
                        children[nxt].insert(a);
                        changed = true;
                    }
                }
                if (changed) {
                    self(nxt, self);
                }
            }
        };
        while (!root.empty()) {
            dfs(root.front(), dfs);
            root.pop();
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = vector<int>(children[i].begin(), children[i].end());
        }
        return ans;
    }
};
