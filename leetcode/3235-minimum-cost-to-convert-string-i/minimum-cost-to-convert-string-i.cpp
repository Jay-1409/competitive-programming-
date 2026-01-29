class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>> adj(26);
        for(int i = 0; i < (int)original.size(); ++i) {
            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }
        vector<vector<long long>> path_cost;
        auto bfs = [&](int src) -> void {
            vector<long long> dist(26, LLONG_MAX);
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
            pq.push({0, src});
            dist[src] = 0;
            while(!pq.empty()) {
                auto [w, u] = pq.top(); pq.pop();
                if(w > dist[u])
                    continue;
                for(auto &[v, _w] : adj[u]) {
                    if(dist[u] + _w < dist[v]) {
                        dist[v] = dist[u] + _w;
                        pq.push({dist[v], v});
                    }
                }
            }
            path_cost.push_back(dist);
        };
        for(int i = 0; i < 26; ++i) {
            bfs(i);
        }
        long long min_cost = 0;
        for(int i = 0; i < (int)source.size(); ++i) {
            if(source[i] != target[i]) {
                //cout << source[i] << " " << target[i] << " " << path_cost[source[i] - 'a'][target[i] - 'a'] << endl;
                if(path_cost[source[i] - 'a'][target[i] - 'a'] == LLONG_MAX)
                    return -1; 
                min_cost += path_cost[source[i] - 'a'][target[i] - 'a'];
            }
        }
        return min_cost;
    }
};