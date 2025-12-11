class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> first, second;
        auto resolve = [&](string s) -> vector<int> {
            int n = s.size();
            int loc = 0;
            vector<int> v;
            while(loc < n) {
                string x;
                while(loc < n && s[loc] != '.') {
                    x.push_back(s[loc++]);
                }
                if(x.empty()) {
                    loc++;
                    continue;
                }
                int num = stoi(x);
                v.push_back(num);
            }
            return v;
        };
        vector<int> x = resolve(version1);
        vector<int> y = resolve(version2);
        int sz = max((int)x.size(), (int)y.size());
        for(int i = 0; i < sz; ++i) {
            if(i >= (int)x.size()) {
                x.push_back(0);
            }
            if(i >= (int)y.size()) {
                y.push_back(0);
            }
            if(x[i] != y[i]) {
                if(x[i] > y[i]) {
                    return 1;
                } else {
                    return -1;
                }
            }
        }
        return 0;
    }
};