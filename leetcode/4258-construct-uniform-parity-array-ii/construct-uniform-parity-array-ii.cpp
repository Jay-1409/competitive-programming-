class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());
        vector<int> v1, v2;
        vector<int> odds;
        for (int x : nums1) {
            if (x & 1) odds.push_back(x);
        }
        bool even = true, odd = true;
        for(int i = 0; i < (int)nums1.size(); ++i) {
            if(nums1[i] & 1) {
                v1.push_back(nums1[i]);
            } else {
                auto it = lower_bound(odds.begin(), odds.end(), nums1[i]) - odds.begin();
                if(it > 0) {
                    int val = nums1[i] - odds[it - 1];
                    if(val >= 1 && (val & 1)) {
                        v1.push_back(val);
                    } else {
                        odd = false;
                    }
                } else {
                    odd = false;
                }
            }
        }

        for(int i = 0; i < (int)nums1.size(); ++i) {
            if(!(nums1[i] & 1)) {
                v2.push_back(nums1[i]);
            } else {
                auto it = lower_bound(odds.begin(), odds.end(), nums1[i]) - odds.begin();
                if(it > 0) {
                    int val = nums1[i] - odds[it - 1];
                    if(val >= 1 && !((val) & 1)) {
                        v2.push_back(val);
                    } else {
                        even = false;
                    }
                } else {
                    even = false;
                }
            }
        }
        return even || odd;
    }
};