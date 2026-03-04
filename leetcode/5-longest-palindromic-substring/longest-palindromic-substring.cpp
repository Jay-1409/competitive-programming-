class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> res(3);
        res[2] = 1;
        res[0] = 0;
        res[1] = 0;
        int n = s.size();
        auto CHECK = [&](int x, int y) -> void {
            int len = 0;
            while(x >= 0 && y < n && (s[x] == s[y])) {
                if(x == y)
                    len++;
                else len += 2;
                if(len > res[2]) {
                    res[0] = x;
                    res[1] = y;
                    res[2] = len;
                }
                x--;
                y++;
            }
        };
        for(int i = 0; i < n - 1; ++i) {
            CHECK(i, i);
            CHECK(i, i + 1);
        }
        return s.substr(res[0], res[1] - res[0] + 1);
    }
};