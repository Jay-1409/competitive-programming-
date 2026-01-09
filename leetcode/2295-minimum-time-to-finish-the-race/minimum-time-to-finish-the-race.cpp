class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        const long long INF = 1e18;
        int n = tires.size();
        vector<long long> PRECOMP(numLaps + 1, INF);
        long long minFirst = INF;
        for (auto &t : tires) {
            minFirst = min(minFirst, (long long)t[0]);
        }
        for (auto &t : tires) {
            long long f = t[0], r = t[1];
            long long cur = f;
            long long sum = 0;
            for (int k = 1; k <= numLaps; k++) {
                sum += cur;
                PRECOMP[k] = min(PRECOMP[k], sum);
                if (cur > 1e9) 
                    break;
                cur *= r;
            }
        }
        vector<long long> dp(numLaps + 1, INF);
        dp[0] = -changeTime; 
        for (int i = 1; i <= numLaps; i++) {
            for (int k = 1; k <= i; k++) {
                if (PRECOMP[k] == INF) break;
                dp[i] = min(dp[i], dp[i - k] + PRECOMP[k] + changeTime);
            }
        }

        return (int)dp[numLaps];
    }
};
