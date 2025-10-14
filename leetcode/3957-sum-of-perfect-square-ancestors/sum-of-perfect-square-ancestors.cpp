class Solution {
private:
    struct Node {
        int id;
        int val;
        vector<Node*> children;
        Node(int id, int val) : id(id), val(val) {}
    };
    struct Graph {
        vector<Node*> nodes;
        Graph(int n, const vector<int>& nums) {
            for (int i = 0; i < n; ++i) {
                nodes.push_back(new Node(i, nums[i]));
            }
        }
        void addEdge(int u, int v) {
            nodes[u]->children.push_back(nodes[v]);
            nodes[v]->children.push_back(nodes[u]);
        }
        Node* getRoot() {
            return nodes[0]; 
        }
    };
public:
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        auto pfr = [&](int n) -> vector<int> {
            vector<int> factors;
            while (n % 2 == 0) {
                factors.push_back(2);
                n /= 2;
            }
            for (int i = 3; i <= sqrt(n); i += 2) {
                while (n % i == 0) {
                    factors.push_back(i);
                    n /= i;
                }
            }
            if (n > 2)
                factors.push_back(n);
            return factors;
        };
        auto extract = [&](int num) -> int {
            vector<int> pf = pfr(num);
            map<int,int> mp;
            for(auto &i : pf) {
                mp[i]++;
            }
            queue<int> q;
            for(auto &i : mp){
                if(i.second & 1) {
                    q.push(i.first);
                }
            }
            int ans = 1;
            while(!q.empty()) {
                ans *= q.front();
                q.pop();
            }
            return ans;
        };
        Graph g(n, nums);
        for (auto &e : edges)
             g.addEdge(e[0], e[1]);
        Node* root = g.getRoot();
        auto rename = [&](Node* cur, Node *parent, auto && self) -> void {
            if(cur) {
                cur->val = extract(cur->val); 
                for(auto &i : (cur->children)) {
                    if(i != parent)
                        self(i, cur, self);
                }
            }
        };
        root = g.getRoot();
        rename(root, nullptr, rename);
        long long cnt = 0;
        auto search = [&](Node* cur, Node* parent, map<int,long long> &frq, auto && self) -> void {
            if(frq[cur->val] > 0) {
                cnt += frq[cur->val];
            }
            for(auto &i : cur->children) {
                if(i != parent)
                {
                    frq[cur->val]++;
                    self(i, cur, frq, self);
                    frq[cur->val]--;
                }
            }
        };
        map<int,long long> mp;
        search(root, nullptr, mp, search);
        return cnt;
    }
};