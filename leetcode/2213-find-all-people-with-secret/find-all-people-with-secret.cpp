class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &i : meetings) {
            if(i[0] == 0 && i[1] == firstPerson) {
                adj[i[0]].push_back({i[1], 0});
            } else {
                adj[i[0]].push_back({i[1], i[2]});
                adj[i[1]].push_back({i[0], i[2]});
            }
        }
        vector<int> min_time_when_node_has_secret(n, INT_MAX);
        set<int> those_who_have_secret;
        queue<int> root;
        root.push(0);
        root.push(firstPerson);
        auto bfs = [&](int root_node) -> void {
            priority_queue<
                pair<int,int>,
                vector<pair<int,int>>,
                greater<>
            > q;
            q.push({0, root_node});
            while(!q.empty()) {
                auto [time, node] = q.top(); 
                q.pop();
                if(time >= min_time_when_node_has_secret[node]) continue;
                min_time_when_node_has_secret[node] = time;
                those_who_have_secret.insert(node);
                for(auto &i : adj[node]) {
                    auto [next_node, desired_time] = i;
                    if(desired_time >= time &&
                       min_time_when_node_has_secret[next_node] >= desired_time) {
                        q.push({desired_time, next_node});
                    }
                }
            }
        };
        while(!root.empty()) {
            bfs(root.front());
            root.pop();
        }
        vector<int> ans(those_who_have_secret.begin(), those_who_have_secret.end());
        return ans;
    }
};
