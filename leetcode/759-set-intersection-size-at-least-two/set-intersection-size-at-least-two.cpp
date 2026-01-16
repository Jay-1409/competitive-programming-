class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [&](const vector<int> &a, const vector<int> &b) {
                 if (a[1] == b[1]) return a[0] > b[0];
                 return a[1] < b[1];
             });

        vector<int> bs_list;
        for (auto &in : intervals) {
            int l = in[0], r = in[1];
            auto it = lower_bound(bs_list.begin(), bs_list.end(), l);
            int cnt = 0;
            if (it != bs_list.end() && *it <= r) {
                cnt++;
                auto it2 = next(it);
                if (it2 != bs_list.end() && *it2 <= r)
                    cnt++;
            }
            if (cnt >= 2) continue;
            if (cnt == 1) {
                bs_list.insert(lower_bound(bs_list.begin(), bs_list.end(), r), r);
            } else {
                bs_list.insert(lower_bound(bs_list.begin(), bs_list.end(), r - 1), r - 1);
                bs_list.insert(lower_bound(bs_list.begin(), bs_list.end(), r), r);
            }
        }
        return bs_list.size();
    }
};
