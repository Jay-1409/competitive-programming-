class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp((int)satisfaction.size() + 1, vector<int>((int)satisfaction.size() + 1, -1));
        auto search = [&](int loc, int picked, int cur_sum, auto && self) -> int {
            if(loc >= (int)satisfaction.size()) {
                return cur_sum;
            }
            if(dp[loc][picked] != -1)
                return dp[loc][picked];
            int skip = 0;
            if(satisfaction[loc] < 0) {
                // we may skip 
                skip = self(loc + 1, picked, cur_sum, self);
            }
            int take = self(loc + 1, picked + 1, cur_sum + ((picked + 1) * satisfaction[loc]), self);
            return dp[loc][picked] = max(take, skip);
        };
        return search(0, 0, 0, search);
    }
};
        /**  NOTES
        
            we have to maximize the the summation of like-time coefficient of a dish 
            for a dish that is equal to to sum_1_to_i * satisfaction[i] considering 1 indexing 
            any incentive to keep negative dishses? -> yes to increase the index, and the multiploication number to the satisfaction level of the dish 
            an optimal way would be to sort the satisfactions
            now we have to choose to take the current negative number or not that is if negative!
            i think that i can take not take on that with proper dp ? 
            keep the states [loc][picked] nsq

        **/