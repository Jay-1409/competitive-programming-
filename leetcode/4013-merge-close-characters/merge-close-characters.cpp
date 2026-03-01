class Solution {
public:
    string mergeCharacters(string s, int k) {
        int offset = 0;
        int n = s.size();
        vector<stack<int>> stk(26);
        for(int i = 0; i < n; ++i) {
            if(stk[s[i] - 'a'].empty()) {
                stk[s[i] - 'a'].push(i - offset);
            } else {
                int cur_loc = i - offset;
                if(cur_loc - stk[s[i]-'a'].top() > k) {
                    stk[s[i] - 'a'].push(cur_loc);
                } else {
                    //got merged into the right!
                    offset++;
                }
            }
        }
        char x = 'a';
        int sz = 0;
        for(auto &I : stk) {
            sz += (int)I.size();
            while(!I.empty()) {
                s[I.top()] = x;
                I.pop();
            }
            x++;
        }
        s.resize(sz);
        return s;
    }
};