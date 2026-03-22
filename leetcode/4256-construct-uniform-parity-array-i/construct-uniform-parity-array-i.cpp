class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> v1, v2;
        bool even = true, odd = true;
        for(int i = 0; i < (int)nums1.size(); ++i) {
            if(nums1[i] & 1) {
                v1.push_back(nums1[i]);
            } else {
                for(int j = 0; j < (int)nums1.size(); ++j) {
                    if(i != j && (nums1[i] - nums1[j]) & 1) {
                        v1.push_back(nums1[i] - nums1[j]);
                        goto goal;
                    }
                }
                odd = false;
                goal:;
            }
        }
        for(int i = 0; i < (int)nums1.size(); ++i) {
            if(!(nums1[i] & 1)) {
                v2.push_back(nums1[i]);
            } else {
                for(int j = 0; j < (int)nums1.size(); ++j) {
                    if(i != j && !((nums1[i] - nums1[j]) & 1)) {
                        v2.push_back(nums1[i] - nums1[j]);
                        goto _goal;
                    }
                }
                even = false;
                _goal:;
            }
        }
        return even | odd;
    }
};