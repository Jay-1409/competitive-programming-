class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;
        vector<bool> used(26, false);
        string st;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (used[c - 'a']) continue;
            while (!st.empty() &&
                st.back() > c &&
                last[st.back() - 'a'] > i) {
                used[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(c);
            used[c - 'a'] = true;
        }
        return st;
    }
    //string smallestSubsequence(string s) {
        // SOLUTION FOR IF WE HAD TO FIND SUBSTRING 
        // set<char> st;
        // for(auto &I : s) {
        //     st.insert(I);
        // }
        // set<char> cur;
        // map<char,int> mp;
        // int l = 0;
        // string running_s;
        // int n = s.size();
        // string ans=s;
        // vector<string> pos_ans;
        // for(int r = 0; r < n; ++r) {
        //     cur.insert(s[r]);
        //     mp[s[r]]++;
        //     running_s.push_back(s[r]);
        //     reverse(running_s.begin(), running_s.end());
        //     while(l <= r && cur.size() == st.size()) {
        //         ans = min(ans, running_s);
        //         pos_ans.push_back(running_s);
        //         running_s.pop_back();
        //         if(mp[s[l]] == 1) {
        //             cur.erase(s[l]);
        //         }
        //         mp[s[l++]]--;
        //     }
        //     reverse(running_s.begin(), running_s.end());
        // }
        // for(auto &i : pos_ans){
        //     reverse(i.begin(), i.end());
        // }
        // for(auto &i : pos_ans) {
        //     ans = min(ans, i);
        // }
        // return ans;
    //}
};