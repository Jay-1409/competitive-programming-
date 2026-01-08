class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> cache(n + 1 , vector<int>(m + 1, INT_MIN));
        auto dfs = [&](int i, int j, auto && self) -> int {
            if(i >= n || j >= m)
                return INT_MIN;
            if(cache[i][j] != INT_MIN) {
                return cache[i][j];
            }
            // for(int _j = j; _j < m; _j++) {
                int res = self(i + 1, j + 1, self);
                if(res == INT_MIN)
                    res = 0;
                //cout << i << " " << _j << " " << res << endl;
                cache[i][j] = max({cache[i][j], nums1[i] * nums2[j] + res, nums1[i] * nums2[j]});
            //}
            cache[i][j] = max(cache[i][j], self(i + 1, j, self));
            cache[i][j] = max(cache[i][j], self(i, j + 1, self));
            return cache[i][j];
        };
        return dfs(0, 0, dfs);
    }
};