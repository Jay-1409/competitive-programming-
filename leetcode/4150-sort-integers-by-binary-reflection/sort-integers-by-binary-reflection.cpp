class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<int> ans;
        vector<int> order;
        for(auto &I : nums) {
            vector<int> binary;
            int n = I;
            int running_num = 0;
            for(int i = 0;i < 32; ++i) {
                int cur = ((n >> i) & 1);
                binary.push_back(cur);
                running_num += (pow(2, i) * cur);
                if(running_num == n)
                    break;
            }
            int new_num = 0;
            reverse(binary.begin(), binary.end());
            for(int i = 0; i < (int)binary.size(); ++i) {
                new_num += (pow(2, i) * binary[i]);
            } 
            order.push_back(new_num);
        }
        vector<pair<int,int>> paired;
        for(int i = 0; i < (int)nums.size(); ++i) {
            paired.push_back({nums[i], order[i]});
        }
        sort(paired.begin(), paired.end(), [&](const pair<int,int> &a, const pair<int,int> &b){
            if(a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;
        });
        for(int i = 0; i < (int)paired.size(); ++i) {
            ans.push_back(paired[i].first);
        }
        return ans;
    }
};