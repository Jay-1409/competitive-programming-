class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mine = prices[0];
        int maxe = 0;
        for(int i = 1; i < (int)prices.size(); ++i) {
            mine = min(mine, prices[i]);
            maxe = max(maxe, prices[i] - mine);
        }
        return maxe;
    }
};