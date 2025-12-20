class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<string> s(m);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                s[j].push_back(strs[i][j]);
            }
        }
        int cnt = 0;
        for(auto  &I : s) {
            if(!is_sorted(I.begin(), I.end())) {
                cnt++;
            }
        }
        return cnt;
    }
};