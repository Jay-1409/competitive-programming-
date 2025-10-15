class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        // binary search on answer and then to validate just one O(n) pass
        int lo = 1;
        int hi = (int)nums.size();
        int ans = 1;
        while(lo <= hi) {
            int k = (hi + lo) / 2;
            int cnt = 1;
            int valid = 0;
            bool poss = false;
            auto f = [&]() -> void {
                if(cnt >= 2 * k) {
                    // can have both made
                    poss |= true;
                } else if(cnt >= k) {
                    // one valid 
                    cnt = 1;
                    valid++;
                    if(valid == 2) {
                        // two valid found and they are contigious 
                        poss |= true;
                    }
                } else {
                    // seq broken 
                    cnt = 1;
                    valid = 0;
                }
            };
            for(int i = 1; i < (int)nums.size(); ++i) {
                if(nums[i] > nums[i - 1]) 
                    cnt++;
                else {
                    f();
                }
            }
            f();
            if(poss) {
                lo = k + 1;
                ans = max(ans, k);
            } else {
                hi = k - 1;
            }
        }
        return ans;
    }
};