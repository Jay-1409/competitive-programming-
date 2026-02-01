class Solution {
public:
    int minimumCost(vector<int>& nums) {
        vector<int> snums = nums;
        sort(snums.begin() + 1, snums.end());
        return snums[0] + snums[1] + snums[2];
    }
};