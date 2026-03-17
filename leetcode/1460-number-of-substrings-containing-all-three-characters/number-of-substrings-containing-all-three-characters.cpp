class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int l = 0;
        int n = s.size();
        map<int,int> src;
        set<int> cur, targ;
        targ.insert('a'); targ.insert('b'); targ.insert('c');
        for(int r = 0; r < n; ++r) {
            src[s[r]]++;
            if(src[s[r]] == 1) {
                cur.insert(s[r]);
            }
            while(cur == targ) {
                cnt += (n - r);
                src[s[l]]--;
                if(src[s[l]] == 0){
                    cur.erase(s[l]);
                }
                l++;
            }
        }   
        return cnt;
    }
};