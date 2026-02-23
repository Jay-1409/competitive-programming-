class Solution {
public:
    bool hasAllCodes(string s, int k) {
        string x;
        set<string> st;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            if(i >= k) {
                st.insert(x);
                reverse(x.begin(), x.end());
                x.pop_back();
                reverse(x.begin(), x.end());
            }
            x.push_back(s[i]);
        }
        st.insert(x);
        long long tot = (1 << (k));
        return tot == st.size();
    }
};