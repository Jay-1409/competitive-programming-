class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> set_of_strings;
        vector<string> repo = {"a", "b", "c"};
        auto search = [&](int loc, int pos, string cur, auto && self) -> void {
            if(loc >= n - 1) {
                set_of_strings.push_back(cur);
                return;
            }
            self(loc + 1, (pos + 1) % 3, cur + repo[(pos + 1) % 3], self);
            self(loc + 1, (pos + 2) % 3, cur + repo[(pos + 2) % 3], self);
        };
        for(int i = 0; i < 3; ++i)
            search(0, i, repo[i], search);
        sort(set_of_strings.begin(), set_of_strings.end());
        return ((int)set_of_strings.size() < k ? "" : set_of_strings[k - 1]);
    }
};