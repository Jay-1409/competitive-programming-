class Solution {
public:
    set<string> vis;
    string best;
    int a, b;
    void dfs(string s) {
        if(vis.count(s)) return;
        vis.insert(s);
        best = min(best, s);
        // take not take
        string addOp = s;
        for(int i = 1; i < addOp.size(); i += 2)
            addOp[i] = ((addOp[i]-'0'+a) % 10) + '0';
        dfs(addOp);
        string rotOp = s;
        rotate(rotOp.begin(), rotOp.begin() + b, rotOp.end());
        dfs(rotOp);
    }

    string findLexSmallestString(string s, int _a, int _b) {
        a = _a; b = _b;
        best = s;
        dfs(s);
        return best;
    }
};
