class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // can we cache on the location ? 
        auto checkInWordDict = [&](string x) -> bool {
            for(auto &i : wordDict) {
                if(i == x)
                    return true;
            }
            return false;
        };
        map<pair<int,string>,bool> dp;
        auto dfs = [&](int loc, string p, auto && self) -> bool {
            if(loc >= (int)s.size()) {
                return p == "";
            }
            if(dp.find({loc, p}) != dp.end()){
                return dp[{loc, p}];
            }
            p.push_back(s[loc]);
            bool make_break = false, dont_break = false;
            if(checkInWordDict(p)) {
                // can break and build new!
                make_break = self(loc + 1, "", self);
            }
            dont_break = self(loc + 1, p, self);
            return dp[{loc, p}] = dont_break || make_break;
        };
        return dfs(0, "", dfs);
    }
};