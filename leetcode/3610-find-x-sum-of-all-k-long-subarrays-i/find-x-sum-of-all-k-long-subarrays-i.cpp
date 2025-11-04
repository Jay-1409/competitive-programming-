class Solution {
public:
    vector<int> findXSum(vector<int>& _nums, int k, int x) {
        auto f = [&](vector<int> nums) -> int {
            map<int,int> mp;
            int sum = 0;
            for(auto &i : nums) {
                mp[i]++;
                sum += i;
            }
            vector<pair<int,int>> v;
            for(auto &i : mp) {
                v.push_back({i.second, i.first});
            }
            if((int)v.size() < x) {
                return sum;
            }
            sort(v.begin(), v.end(), [&](const pair<int,int>&a, const pair<int,int> &b) {
                if(a.first == b.first) {
                    return a.second > b.second;
                } 
                return a.first > b.first;
            });
            int _sum = 0;
        
            for(int i = 0; i < min(x, (int)v.size()); ++i) {
                _sum += v[i].first * v[i].second;
            }

            return _sum;
        };
        vector<int> ans;
        for(int i = 0; i <= (int)_nums.size() - k; ++i) {
            vector<int> t;
            for(int j = i; j < i + k; ++j) {
                t.push_back(_nums[j]);
            }
            ans.push_back(f(t));
        }
        return ans;
    }
};