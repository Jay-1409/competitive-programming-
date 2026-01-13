class Solution {
public:
    struct State {
        int node;
        int mask;
        int dist;
    };
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; ++i) {
            for(auto &j : graph[i])
                adj[i].push_back(j);
        }
        vector<vector<int>> cache(n + 1, vector<int>(12000, -1));
        queue<State> q;
        int final_mask = 0;
        for(int i = 0; i < n; ++i) {
            State curstate;
            curstate.node = i;
            curstate.mask = (1 << i);
            curstate.dist = 0;
            q.push(curstate);
            final_mask |= (1 << i);
        }
        int ans = INT_MAX;
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            if(cache[u.node][u.mask] != -1) {
                continue;
            }
            cache[u.node][u.mask] = 1;
            for(auto &i : adj[u.node]) {
                int next_mask = u.mask | (1 << i);
                if(next_mask == final_mask) {
                    ans = min(ans, u.dist + 1);
                    continue;
                }
                if(cache[i][next_mask] != -1) {
                    continue;
                }
                State next_state;
                next_state.node = i;
                next_state.mask = next_mask;
                next_state.dist = u.dist + 1;
                q.push(next_state);
            }
        }   
        return (ans == INT_MAX ? 0 : ans);
    }
};