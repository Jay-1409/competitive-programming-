#include <bits/stdc++.h>
using namespace std;

struct FenwickXor {
    int n;
    vector<int> bit; // XOR Fenwick (1-indexed)
    FenwickXor(int n=0){ init(n); }
    void init(int _n){ n=_n; bit.assign(n+1,0); }
    void add(int i, int val){ // point add (XOR)
        for(; i<=n; i += i&-i) bit[i] ^= val;
    }
    // range xor update [l, r]
    void range_xor(int l, int r, int val){
        if(l>r) return;
        add(l, val);
        if(r+1<=n) add(r+1, val);
    }
    // point query at i (prefix xor)
    int point(int i){
        int res = 0;
        for(; i>0; i -= i&-i) res ^= bit[i];
        return res;
    }
};

class Solution {
public:
    int LOG = 20;
    vector<vector<int>> up;
    vector<int> depth, tin, tout;
    int timer = 0;
    vector<int> base_pref;      // pref from root using initial masks
    vector<int> cur_mask;       // current mask for each node (1<<c)
    FenwickXor bit;
    vector<vector<int>> adj;

    void dfs_prep(int v, int p){
        tin[v] = ++timer;
        up[0][v] = p;
        if(p == -1) depth[v] = 0;
        else depth[v] = depth[p] + 1;
        // compute base_pref: parent's base_pref XOR this node mask
        if(p == -1) base_pref[v] = cur_mask[v];
        else base_pref[v] = base_pref[p] ^ cur_mask[v];

        for(int to : adj[v]){
            if(to == p) continue;
            dfs_prep(to, v);
        }
        tout[v] = timer;
    }

    int lca(int a, int b){
        if(depth[a] < depth[b]) swap(a,b);
        int diff = depth[a] - depth[b];
        for(int k=0; diff; ++k){
            if(diff & 1) a = up[k][a];
            diff >>= 1;
        }
        if(a == b) return a;
        for(int k = LOG-1; k>=0; --k){
            if(up[k][a] != -1 && up[k][a] != up[k][b]){
                a = up[k][a];
                b = up[k][b];
            }
        }
        return up[0][a];
    }

    // parse two ints from query string (works like original get_digits)
    pair<int,int> get_digits(const string &q){
        int a=0,b=0,i=0;
        while(i< (int)q.size() && !isdigit(q[i])) ++i;
        while(i< (int)q.size() && isdigit(q[i])) { a = a*10 + (q[i]-'0'); ++i; }
        while(i< (int)q.size() && !isdigit(q[i])) ++i;
        while(i< (int)q.size() && isdigit(q[i])) { b = b*10 + (q[i]-'0'); ++i; }
        return {a,b};
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        // build graph
        adj.assign(n, {});
        for(auto &e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // prepare data structures
        cur_mask.assign(n, 0);
        for(int i=0;i<n;++i) cur_mask[i] = 1 << (s[i]-'a');

        tin.assign(n, 0);
        tout.assign(n, 0);
        base_pref.assign(n, 0);
        depth.assign(n, 0);

        LOG = 1;
        while((1<<LOG) <= n) ++LOG;
        up.assign(LOG, vector<int>(n, -1));

        timer = 0;
        // root at 0 (same as your code)
        dfs_prep(0, -1);

        // fill binary lifting table
        for(int k=1;k<LOG;++k){
            for(int v=0; v<n; ++v){
                int mid = up[k-1][v];
                up[k][v] = (mid == -1 ? -1 : up[k-1][mid]);
            }
        }

        // Fenwick over euler (1..n)
        bit.init(n);

        vector<bool> ans;
        ans.reserve(queries.size());

        for(const string &Q : queries){
            if(Q.empty()) continue;
            if(Q[0] == 'q'){ // query u v
                auto [u,v] = get_digits(Q);
                // compute current pref using base_pref XOR fenwick point
                int pref_u = base_pref[u] ^ bit.point(tin[u]);
                int pref_v = base_pref[v] ^ bit.point(tin[v]);
                int w = lca(u,v);
                int parity = pref_u ^ pref_v ^ cur_mask[w];
                // palindrome if at most one bit set in parity
                bool ok = (parity == 0) || ((parity & (parity - 1)) == 0);
                ans.push_back(ok);
            } else { // update: format assumed like "u x c" or similar; original used last char as new char
                auto [u, maybe] = get_digits(Q);
                char newc = Q.back();
                int newmask = 1 << (newc - 'a');
                int delta = cur_mask[u] ^ newmask;
                if(delta != 0){
                    // flip subtree of u by delta
                    bit.range_xor(tin[u], tout[u], delta);
                    cur_mask[u] = newmask;
                }
            }
        }
        return ans;
    }
};