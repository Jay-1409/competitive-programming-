class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set<int> st, empty_set={};
        int cnt = 1;
        for(auto &i : rolls) {
            st.insert(i);
            if(st.size() == k) {
                cnt++;
                st = empty_set;
            }
        }
        return cnt;
    }
};