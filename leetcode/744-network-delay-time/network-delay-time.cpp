class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto &i : times) {
            adj[i[0]].push_back(make_pair(i[1], i[2]));
                                        // to, time
        }
        queue<int> q;
        q.push(k);
        dist[k] = 0;
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            for(auto &[next, time] : adj[node]) {
                if(dist[next] > dist[node] + time) {
                    dist[next] = dist[node] + time;
                    q.push(next);
                } 
            }
        }
        return(*max_element(dist.begin() + 1, dist.end()) == INT_MAX ? -1 : *max_element(dist.begin() + 1, dist.end()));
    }
};