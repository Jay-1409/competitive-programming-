class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> freq;
        for (auto x : nums2) {
            freq[x * k]++;
        }
        long long ans = 0;
        for (auto x : nums1) {
            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    int d1 = d;
                    int d2 = x / d;
                    if (freq.count(d1)) ans += freq[d1];
                    if (d1 != d2 && freq.count(d2)) ans += freq[d2];
                }
            }
        }
        return ans;
    }
};
