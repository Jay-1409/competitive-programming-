class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        for(auto &I : nums) {
            if(I % 3 != 0) {
                cnt++;
            }
        }
        return cnt;
    }
};