class Solution {
public:
    int minimumK(vector<int>& nums) {
        int lo = 1;
        int hi = 1e9;
        bool need_to_check = false;
        for(auto &I:nums) {
            if(I > 0) {
                need_to_check = true;
            }
        }
        if(!need_to_check) {
            return 0;
        }
        auto check = [&](int k) -> bool {
            int ops = 0;
            for(auto &I : nums) {
                ops += (I + k - 1) / k;
            }
            return ops <= (1LL * k * k);
        };
        int ans = INT_MAX;
        while(lo <= hi) {
            int mid = (hi + lo) / 2;
            if(check(mid)) {
                hi = mid - 1;
                ans = min(ans, mid);
            } else { 
                lo = mid + 1;
            }
        }
        return ans;
    }
};