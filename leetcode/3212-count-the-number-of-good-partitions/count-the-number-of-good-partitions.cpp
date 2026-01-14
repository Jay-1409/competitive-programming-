class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        map<int,int> first, last;
        set<int> st;
        for(int i = 0; i < n; ++i) {
            if(first.find(nums[i]) == first.end())
                first[nums[i]] = i;
            last[nums[i]] = i;
            st.insert(nums[i]);
        }
        vector<pair<int,int>> events;
        for(auto &I : st) {
            events.push_back({first[I], last[I]});
        }
        sort(events.begin(), events.end(), [](const pair<int,int> &a, const pair<int,int> &b){
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        int cnt = 0;
        vector<pair<int,int>> merged;
        int prevend = events[0].second;
        for (int i = 1; i < events.size(); i++) {
            if (events[i].first > prevend) {
                cnt++;
                prevend = events[i].second;
            } else {
                prevend = max(prevend, events[i].second);
            }
        }
        int val = 1;
        const long long mod = 1e9 + 7;
        while(cnt--) {
            val = (val * 2) % mod;
        }
        return val;
    }
};