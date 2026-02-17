class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> vec = {8, 4, 2, 1, 0};
        vector<pair<int,int>> out;
        vector<pair<int,int>> pos_hour_combs, pos_min_combs;
        int n = vec.size();
        int lim = 11;
        auto dfs = [&](int loc, int cur_sum, int led, auto && self) -> void {
            if(loc == n) {
                out.push_back(make_pair(led, cur_sum));
                return;
            }
            //take
            if(cur_sum + vec[loc] <= lim) {
                self(loc + 1, cur_sum + vec[loc], led + (vec[loc] != 0), self);
            } 
            //not take
            self(loc + 1, cur_sum, led, self);
        };
        dfs(0, 0, 0, dfs);
        pos_hour_combs = out;
        vec.clear();
        vec = {32, 16, 8, 4, 2, 1, 0};
        lim = 59;
        n = vec.size();
        dfs(0, 0, 0, dfs);
        pos_min_combs = out;
        set<string> st;
        for(auto &[led1,hour] : pos_hour_combs) {
            for(auto &[led2, min] : pos_min_combs) {
                if(led1 + led2 == turnedOn) {
                // cout << led1 << " " << hour << " " << led2 << " " << min << endl;
                    string shour = to_string(hour);
                    string smin = to_string(min);
                    // if(shour == "0" && smin == "0")
                    //     continue;
                    if(smin.size() == 1) {
                        smin = "0" + smin;
                    }
                    st.insert(shour + ":" + smin);
                }
            }
        }
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};