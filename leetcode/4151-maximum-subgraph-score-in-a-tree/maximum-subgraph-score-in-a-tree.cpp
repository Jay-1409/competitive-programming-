class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> dp(n, 0);
        vector<int> ans(n, 0);
        function<void(int,int)> dfs1 = [&](int u, int p) {
            dp[u] = (good[u] == 1 ? 1 : -1);
            for (int v : g[u]) {
                if (v == p) continue;
                dfs1(v, u);
                if (dp[v] > 0) dp[u] += dp[v];  
            }
        };
        function<void(int,int,int)> dfs2 = [&](int u, int p, int parentContribution) {
            ans[u] = dp[u] + parentContribution;
            for (int v : g[u]) {
                if (v == p) continue;
                int withoutV = ans[u] - max(0, dp[v]);
                if (withoutV < 0) withoutV = 0;
                dfs2(v, u, withoutV);
            }
        };
        dfs1(0, -1);
        dfs2(0, -1, 0);
        return ans;
    }
};

/** PROMPT
1) i want you to first do kadanes on this graphj, and save dp[u] = bnest sum found for the subgraph of u, v != p
2) then i want you to choose like this 
    - take the currenta nd move to the next, dont change the pointer 
    - take the current and move to the next and chnge the pointer to the next 
    - do not take at all 

**/