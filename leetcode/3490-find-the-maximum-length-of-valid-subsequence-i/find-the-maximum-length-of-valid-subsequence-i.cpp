class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0, even = 0, oddEve = 0, eveReq1 = 0, eveOdd = 0, eveReq2 = 1;
        for(int val : nums) {
            if(val & 1) {
                odd++;
                if(!eveReq1) oddEve++, eveReq1 = 1;
                if(!eveReq2) eveOdd++, eveReq2 = 1;
            }
            else {
                even++;
                if(eveReq1) oddEve++, eveReq1 = 0;
                if(eveReq2) eveOdd++, eveReq2 = 0;
            }
        }
        return max({odd, even, oddEve, eveOdd});
    }
};