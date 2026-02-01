class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    int _n;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        _n =  n;
        for(auto &i : edges) {
            adj[i[0]].push_back({i[1], i[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(_n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, node1});
        dist[node1] = 0;
        while(!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();
            if(w > dist[u])
                continue;
            for(auto &[v, _w] : adj[u]) {
                if(dist[v] > dist[u] + _w) {
                    dist[v] = dist[u] +_w;
                    pq.push({dist[v], v});
                }
            }
        }
        return (dist[node2] == INT_MAX ? -1 : dist[node2]);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */