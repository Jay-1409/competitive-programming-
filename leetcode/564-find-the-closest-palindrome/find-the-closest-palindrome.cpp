class Solution {
public:
    string nearestPalindromic(string n) {
        if(n.size() == 1) {
            long long x = stoll(n);
            string xx;
            if(x == 0)  {
                xx = to_string(x + 1);
                return xx;
            }
            else {
                xx = to_string(x - 1);
                return xx;
            }
        }
        long long len_appropriate = ((long long)n.size() + 1) / 2;
        string middle_good = n.substr(0, len_appropriate);
        string t = middle_good;
        reverse(t.begin(), t.end());
        long long num_middle_good = stoll(middle_good);
        long long plus = num_middle_good + 1;
        long long minus = num_middle_good - 1;
        middle_good += t;
        long long __ = stoll(middle_good);
        vector<long long> possible;
       // possible.push_back(__);
        auto to_string_rev_back_to_num= [&](long long x) -> long long {
            string tt = to_string(x);
            string _ = tt;
            reverse(tt.begin(), tt.end());
            if((long long)n.size() & 1) {
                _.pop_back();
            }
            _ += tt;
            long long nm = stoll(_);
            return nm;
        };
        possible.push_back(to_string_rev_back_to_num(plus));
        possible.push_back(to_string_rev_back_to_num(minus));
        //if(n.size() & 1)
            possible.push_back(to_string_rev_back_to_num(num_middle_good));
        long long target = stoll(n);
        long long gap = LLONG_MAX;
        long long num = LLONG_MIN;
        long long nn = 1;
        long long _t = n.size();
        long long nnn = 0;
        while(_t--) {
            nn *= 10;
            if(nnn == 0)
                nnn = 1;
            else
                nnn *= 10;
        }
        //cout << nnn <<" " << nn << endl;
        possible.push_back(nnn + 1);
        possible.push_back(nnn - 1);   
        possible.push_back(nn + 1);
        possible.push_back(nn - 1);
        sort(possible.begin(), possible.end());
        for(auto &i : possible) {
            if(abs( i - target) < gap && abs(i - target) > 0) {
                gap = abs(i - target);
                num = i;
            }
        }
        // for(auto &i :possible) {
        //     cout << i << " ";
        // }
        string a= to_string(num);
        return a;
    }
};