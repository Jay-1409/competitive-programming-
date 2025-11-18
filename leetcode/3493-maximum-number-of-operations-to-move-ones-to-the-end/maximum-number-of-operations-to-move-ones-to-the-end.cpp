class Solution {
public:
    int maxOperations(string s) {
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < (int)s.size(); ++i) {
            if(s[i] == '1') {
                cnt++;
                continue;
            }
            int j = i;
            while(j < (int)s.size() && s[j] == '0') {
                j++;
            }
            if(j > i)
                i = j - 1;
            ans += cnt;
        }
        return ans;
    }
};