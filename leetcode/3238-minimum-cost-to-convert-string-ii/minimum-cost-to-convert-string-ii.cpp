class Solution {
public:
    struct Trie {
        int id = -1;
        Trie* next[26] = {};
    };
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = cost.size();
        unordered_map<string, int> unique_id;
        auto id = [&](string s) -> int {
            return unique_id[s];
        };
        int uq_id_xt = 0;
        for(auto &i : original) {
            if(unique_id.find(i) == unique_id.end()) {
                unique_id[i] = uq_id_xt++;
            }
        }
        for(auto &i : changed) {
            if(unique_id.find(i) == unique_id.end()) {
                unique_id[i] = uq_id_xt++;
            }
        }
        vector<vector<pair<int,int>>> adj(uq_id_xt);
        for(int i = 0; i < n; ++i) {
            adj[id(original[i])].push_back(make_pair(id(changed[i]), cost[i]));
        }
        vector<vector<long long>> path_cost;
        auto bfs = [&](int src) -> void {
            vector<long long> dist(uq_id_xt, LLONG_MAX);
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
        for(int i = 0; i < uq_id_xt; ++i){
            bfs(i);
        }
        int m = source.size();
        vector<long long> dp(m + 1, LLONG_MAX);
        dp[0] = 0;
        auto handle_cost = [&](int s, int t) -> long long {
            return path_cost[s][t];
        };
        Trie* root = new Trie();
        auto insert_into_trie = [&](vector<string> v) -> void {
            for(auto &i : v) {
                Trie* cur = root;
                for(auto &j : i) {
                    int x = j - 'a';
                    if(cur->next[x]) {
                        cur = cur->next[x];
                    } else {
                        cur->next[x] = new Trie();
                        cur = cur->next[x];
                    }
                }
                cur->id = id(i);
            }
        };
        insert_into_trie(original);
        insert_into_trie(changed);
        for (int i = 0; i < m; ++i) {
            if (dp[i] == LLONG_MAX) continue;
            if (source[i] == target[i])
                dp[i + 1] = min(dp[i + 1], dp[i]);
            Trie *s = root;
            Trie *t = root;
            for (int j = i; j < m; ++j) {
                if(s->next[source[j] - 'a'] && t->next[target[j] - 'a']) {
                    s = s->next[source[j] - 'a'];
                    t = t->next[target[j] - 'a'];
                    if(s->id == -1 || t->id == -1)
                        continue;
                    long long res = handle_cost(s->id,t->id);
                    if (res != LLONG_MAX)
                        dp[j + 1] = min(dp[j + 1], dp[i] + res);
                } else
                    break;
            }
        }
        return (dp[m] != LLONG_MAX ? dp[m] : -1);
    }
};