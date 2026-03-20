class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0;
        int mine = INT_MAX;
        for(int i = 0;i < (int)prices.size(); ++i) {
            mine = min(mine, prices[i]);
            prof = max(prof, prices[i] - mine);
        }
        return prof;
    }
};