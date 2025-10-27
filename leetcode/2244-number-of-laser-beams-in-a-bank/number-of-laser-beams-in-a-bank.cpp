class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int ans = 0;
        for(auto &i : bank) {
            int cur = 0;
            for(auto &j : i) {
                cur += (j - '0');
            }
            ans += prev * cur;
            if(cur > 0)
                prev = cur;
            
        }
        return ans;
    }
};

/**

**/