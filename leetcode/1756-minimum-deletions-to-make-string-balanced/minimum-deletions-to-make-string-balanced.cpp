class Solution {
public:
    int minimumDeletions(string s) {
        vector<pair<char, int>> v;
        char current = '-1';
        int cnt = 0;
        for(auto &i : s) {
            if(i != current) {
                v.push_back({current, cnt});
                current = i;        
                cnt = 1;
            } else {
                cnt++;
            }
        }
        if(cnt > 0) {
            v.push_back({current, cnt});
        }
        int bs = 0;
        cnt = 0;
        for(int i = 1; i < (int)v.size(); ++i) {
            if(v[i].first == 'b') {
                bs += v[i].second;
            } else {
                if(bs > 0) {
                    cnt = min(bs, cnt + v[i].second);
                }
            }
        }
        return cnt;
    }
};