class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> present;
        unordered_map<int, bool> vis;
        for(auto &i : nums) {
            present[i] = true;
        }
        auto dfs = [&](int nums, auto && self) -> int {
            if(!present[nums] || vis[nums])
                return 0;
            vis[nums] = true;
            return 1 + self(nums + 1, self) + self(nums - 1, self);
        };
        int maxe = 0;
        for(auto &i : nums) {
            if(!vis[i]) {
                maxe = max(dfs(i, dfs), maxe);
            }
        }
        return maxe;
    }
};
/**
    just do dfs
**/