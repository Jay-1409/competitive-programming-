class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<int>> adj(n);
        for(auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        unordered_map<int, unordered_map<int,int>> cache;
        auto dfs = [&](int node, int par, int times, auto && self) -> int {
            if(cache.count(node) && cache[node].count(times)) {
                return cache[node][times];
            }
            int score = 0;
            int node_val = (times <= 14 ? (coins[node] / (1 << times)) : 0);
            int do_op1 = node_val - k;
            int do_op2 = node_val / 2;
            for(auto &child : adj[node]) {
                if(child == par)
                    continue;
                do_op1 += self(child, node, times, self);
                if(times < 14) //## imp purning
                    do_op2 += self(child, node, times + 1, self);
            }
            score = max(do_op1, do_op2);
            return cache[node][times] = score;
        };
        return dfs(0, -1, 0, dfs);
    }
};

/**
NOTES
- dp[node][times] = all the nodes in the subtree rooted at [node] have had their values divided by 2 [times] times. 
- log2(10000) = 13.287712379549
- so after ~14 divisions by two the value of any node is going to be 0;
**/