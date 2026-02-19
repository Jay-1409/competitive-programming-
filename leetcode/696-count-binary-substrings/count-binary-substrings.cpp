class Solution {
public:
    int countBinarySubstrings(string s) {
        stack<char> zeros, ones;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && s[i] != s[i - 1]) {
                if (s[i] == '0')
                    zeros = stack<char>();
                else
                    ones = stack<char>();
            }
            if (s[i] == '0') {
                zeros.push('0');
                if (!ones.empty()) {
                    ones.pop();
                    cnt++;
                }
            } 
            else {
                ones.push('1');
                if (!zeros.empty()) {
                    zeros.pop();
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
