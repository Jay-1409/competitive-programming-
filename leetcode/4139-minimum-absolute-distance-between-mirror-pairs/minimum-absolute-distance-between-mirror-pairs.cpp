class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        map<int, int> rev_cnt1;
        auto rev = [&](int x) -> int {
            string s = to_string(x);
            reverse(s.begin(), s.end());
            x = stoi(s);
            return x;
        };
        int cnt = 0;
        int loc = 0;
        int ans = INT_MAX;
        for(auto &I : nums) {
            if(rev_cnt1.find(I) != rev_cnt1.end()) {
                ans = min(ans, loc - rev_cnt1[I]);
            }
            rev_cnt1[rev(I)] = loc;
            loc++;
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};