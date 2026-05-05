class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& vis) {
        vis[u] = 1;
        for(int v : adj[u]) {
            if(vis[v] == 0) {
                if(dfs(v, adj, vis)) return true;
            } else if(vis[v] == 1) {
                return true;
            }
        }
        vis[u] = 2;
        return false;
    }
    bool hasCycle(int n, vector<vector<int>>& adj) {
        vector<int> vis(n, 0);
        for(int i = 0; i < n; ++i) {
            if(vis[i] == 0) {
                if(dfs(i, adj, vis)) return true;
            }
        }
        return false;
    }
    bool isPrintable(vector<vector<int>>& targetGrid) {
        vector<pair<int,int>> first(121, make_pair(-1, -1));
        vector<pair<int,int>> last(121, make_pair(-1, -1));
        int n = targetGrid.size();
        int m = targetGrid[0].size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(first[targetGrid[i][j]].first == -1) {
                    first[targetGrid[i][j]] = make_pair(i, j);
                }
                last[targetGrid[i][j]] = make_pair(i, j);
            }
        }
        vector<int> sides(121, 0);
        for(int i = 1; i <= 120; ++i) {
            if(first[i].first != -1 && last[i].first != -1) {
                sides[i] = max(abs(first[i].first - last[i].first), abs(first[i].second - last[i].second)); 
            }
        }       
        vector<vector<vector<int>>> grid(n, vector<vector<int>>(m));
        for(int c = 1; c <= 120; ++c) {
            if(first[c].first != -1) {
                int r1 = min(first[c].first, last[c].first);
                int r2 = max(first[c].first, last[c].first);
                int c1 = min(first[c].second, last[c].second);
                int c2 = max(first[c].second, last[c].second);
                for(int i = r1; i <= r2; ++i) {
                    for(int j = c1; j <= c2; ++j) {
                    grid[i][j].push_back(c);
                    }
                }
            }
        }
        vector<vector<int>> adj(121);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                for(auto &k : grid[i][j]) {
                    if(k != targetGrid[i][j]) {
                        adj[k].push_back(targetGrid[i][j]);
                    }
                }
            }
        }
        return !hasCycle(121, adj);
    }
};