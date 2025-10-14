class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> mp;
        for(auto &i : s) 
            mp[i]++;
        int part = 1;
        set<int> st;
        int prev = 0;
        vector<int> ans;
        for(int i = 0; i < (int)s.size(); ++i) {
            st.insert(s[i]);
            mp[s[i]]--;
            if(mp[s[i]] == 0)
                st.erase(s[i]);
            if(st.empty()) {
                ans.push_back(i - prev + 1);
                prev = i + 1;
            }
        }
        return ans;
    }
};