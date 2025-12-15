class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo = 1;
        int hi = *max_element(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int best = INT_MAX;
        while(lo <= hi) {
            int mid = (hi + lo) / 2;
            auto check = [&]() -> bool {
                long long cnt = 0;
                for(auto &i : nums) {
                    int x = i;
                    if(x > mid) {
                        int turns = ((x - 1) / mid);
                        cnt += turns;
                    }
                }
                return cnt <= maxOperations;
            };
            if(check()) {
                hi = mid - 1;
                best = min(best, mid);
            } else {
                lo = mid + 1;
            }
        }
        return best;
    }
};