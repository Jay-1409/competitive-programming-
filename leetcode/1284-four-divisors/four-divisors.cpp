class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto &i : nums) {
            int cnt = 0;
            int sm = 0;
            for(int j = 1; j * j <= i; ++j) {
                if(i % j == 0) {
                    int d1 = j;
                    int d2 = i / j;
                    if(d1 != d2) {
                        sm += d1;
                        sm+= d2;
                        cnt += 2;
                    } else {
                        cnt++;
                        sm+=d1;
                    }
                }
            }
            if(cnt == 4)
                ans+=sm;
        }
        return ans;
    }
};