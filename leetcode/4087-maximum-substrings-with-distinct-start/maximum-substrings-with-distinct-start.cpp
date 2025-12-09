class Solution {
public:
    int maxDistinct(string s) {
        int cnt = 0;
        set<char> st;
        for(auto &i : s) {
            st.insert(i);
        }
        return (int)st.size();
    }
};