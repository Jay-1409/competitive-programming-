class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &i : edges) {
            adj[i[0]].push_back(make_pair(i[1], i[2]));
            adj[i[1]].push_back(make_pair(i[0], 2 * i[2]));
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        pq.push(make_pair(0, 0));
        while(!pq.empty()) {
            auto [w_, u] = pq.top();
            pq.pop();
            if(dist[u] < w_) {
                continue;
            }
            for(auto &[v, w] : adj[u]) {
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        return (dist[n - 1] == INT_MAX ? -1 : dist[n - 1]);
    }
};