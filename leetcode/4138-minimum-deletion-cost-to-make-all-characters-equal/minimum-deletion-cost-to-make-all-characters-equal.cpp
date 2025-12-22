class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long mine = LLONG_MAX;
        for(char c = 'a'; c <= 'z'; ++c) {
            long long current_cost = 0;
            for(int i = 0; i < (int)s.size(); ++i) {
                if(s[i] != c) {
                    current_cost += cost[i];
                }
            }
            mine = min(mine, current_cost);
        }
        return mine;
    }
};