class Solution {
public:
    vector<int> pfx;
    int n;
    Solution(vector<int>& w) {
        n = w.size();
        vector<int> p(n);
        pfx.resize(n);
        pfx[0] = w.front();
        for(int i = 1; i < n; ++i) {
            pfx[i] = pfx[i - 1] + w[i];
        }
    }
    int pickIndex() {
        int randomidx = rand() % pfx[n - 1] + 1;
        auto it = lower_bound(pfx.begin(), pfx.end(), randomidx) - pfx.begin();
        return it;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */