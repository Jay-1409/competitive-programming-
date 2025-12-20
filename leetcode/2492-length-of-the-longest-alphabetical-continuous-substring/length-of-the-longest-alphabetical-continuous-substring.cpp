class Solution {
public:
    int longestContinuousSubstring(string s) {
        int maxe =0 ;
        int n = s.size();
        int cnt = 1;
        for(int i = 0 ;i < n; ++i) {
            if(i > 0) {
                if(s[i] == (s[i - 1] + 1)) {
                    cnt++;
                } else {
                    maxe = max(cnt, maxe);
                    cnt = 1;
                }
            }
        }
        return max(maxe, cnt);
    }
};