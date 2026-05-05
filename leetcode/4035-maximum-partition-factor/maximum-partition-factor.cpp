class Solution {
public:
    int maxPartitionFactor(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 2)
            return 0;
        int hi = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                hi = max(hi, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
            }
        }
        int lo = 0, ans = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            vector<vector<int>> adj(n);
            for(int i = 0; i < n; ++i) {
                for(int j = i + 1; j < n; ++j) {
                    if(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) <= mid) {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
            vector<int> color(n, -1);
            bool ok = true;
            for(int i = 0; i < n && ok; ++i) {
                if(color[i] == -1) {
                    queue<int> q;
                    q.push(i);
                    color[i] = 0;
                    while(!q.empty() && ok) {
                        int u = q.front(); q.pop();
                        for(int v : adj[u]) {
                            if(color[v] == -1) {
                                color[v] = color[u] ^ 1;
                                q.push(v);
                            } else if(color[v] == color[u]) {
                                ok = false;
                                break;
                            }
                        }
                    }
                }
            }
            if(ok) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans + 1;
    }
};