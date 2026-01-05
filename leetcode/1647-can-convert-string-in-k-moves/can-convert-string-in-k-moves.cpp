class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size() != t.size())
            return false;
        map<int,int> mp;
        int n = s.size();
        set<int> st;
        for(int i = 0; i < n; ++i) {
            int dist = (t[i] - s[i]);
            if(dist < 0) {
                dist = (26 - (s[i] - 'a' + 1)) + (t[i] - 'a' + 1);
            }
            if(dist == 0)
                continue;
            bool ok = false;
            int lo = 0;
            int hi = 100000;
            int ans = INT_MAX;
            while(lo <= hi) {
                int mid = (hi + lo) / 2;
                int val = dist + mid * 26;
                if(val > k) {
                    hi = mid - 1;
                } else {
                    if(st.find(val) == st.end()) {
                        hi = mid - 1;
                        ans = min(ans, mid);
                    } else {
                        lo = mid + 1;
                    }
                }
            }
            if(ans == INT_MAX)
                ok = false;
            else 
                {
                    ok = true;
                    st.insert(dist + 26 * ans);
                }
            if(!ok)
                return false;
    
        }   
        return true;
    }
};