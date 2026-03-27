class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {
        map<int, vector<int>> hori, verti;
        map<int, pair<int,int>> trace;
        int node_number = 0;
        for(auto &i : points) {
            trace[node_number] = make_pair(i[0], i[1]);
            hori[i[0]].push_back(node_number);
            verti[i[1]].push_back(node_number++);
        }
        vector<int> vis(node_number, false);
        int curr_cluster_counter = 0;
        set<int> used_col, used_row;
        auto dfs = [&](int node, auto && self) -> void {
            vis[node] = true;
            curr_cluster_counter++;
            int cur_col = trace[node].first;
            int cur_row = trace[node].second;
            if(used_col.find(cur_col) != used_col.end())
                goto bypasscol;
            used_col.insert(cur_col);
            for(auto &i : hori[cur_col]) {
                if(!vis[i])
                    self(i, self);
            }
            bypasscol:;
            if(used_row.find(cur_row) != used_row.end())
                goto bypassrow;
            used_row.insert(cur_row);
            for(auto &j : verti[cur_row]) {
                if(!vis[j])
                    self(j, self);
            }
            bypassrow:;
        };
        vector<int> cluster_size;
        for(int i = 0; i < node_number; ++i) {
            if(!vis[i]) {
                curr_cluster_counter = 0;
                dfs(i, dfs);
                cluster_size.push_back(curr_cluster_counter);
            }
        }
        sort(cluster_size.begin(), cluster_size.end());
        int n = cluster_size.size();
        if(n > 1) 
            return cluster_size[n - 1] + cluster_size[n - 2] + 1;
        return cluster_size.back() + 1;
    }
};