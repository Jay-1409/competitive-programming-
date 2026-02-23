class Solution {
public:
    bool hasAllCodes(string s, int k) {
        string x;
        unordered_map<int, bool> st;
        int n = s.size();
        int val = 0;
        for(int i = 0; i < n; ++i) {
            if(i >= k) {
                st[val] = true;
                val &= (INT_MAX >> (32 - k));
            }
            val <<= 1;
            if(s[i] == '1')
                val |= 1;
        }
        st[val] = true;
        long long tot = (1 << (k));
        return tot == st.size();
    }
};