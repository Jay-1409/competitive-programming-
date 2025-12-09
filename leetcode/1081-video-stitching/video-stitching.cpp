class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        
        // Step 1: Build graph adjacency list
        vector<vector<int>> g(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                // Edge i -> j if j starts after i and within reach
                if(clips[i][1] >= clips[j][0]) {
                    g[i].push_back(j);
                }
            }
        }

        // Step 2: BFS shortest distance
        queue<int> q;
        vector<int> dist(n, INT_MAX);

        // nodes that can start at 0
        for(int i = 0; i < n; i++) {
            if(clips[i][0] == 0) {
                q.push(i);
                dist[i] = 1;
            }
        }

        // BFS
        while(!q.empty()) {
            int u = q.front(); 
            q.pop();

            for(int v : g[u]) {
                if(dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        // Step 3: Find minimum jumps that reach >= time
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(clips[i][1] >= time) {
                ans = min(ans, dist[i]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
