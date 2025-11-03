class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int cnt = 0;
        for(int i = 0; i < n - 1; ++i) {
            int j = i + 1;
            int sum = neededTime[i];
            int maxe = neededTime[i];
            int len = 0;
            while(colors[i] == colors[j]) {
                sum += neededTime[j];
                maxe = max(maxe, neededTime[j++]);
                len++;
            }
            cnt += (sum - maxe);
            if(j > i + 1) {
                i = j - 1;
            }
        }
        return cnt;
    }
};