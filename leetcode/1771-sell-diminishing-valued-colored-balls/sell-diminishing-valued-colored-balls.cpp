class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long sumN(long long n) {
        n %= MOD;
        return n * (n + 1) % MOD * ((MOD + 1) / 2) % MOD;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.rbegin(), inventory.rend());

        int n = inventory.size();
        long long ans = 0;
        for (int i = 0; i < n && orders > 0; ++i) {
            long long curr = inventory[i];
            long long next = (i + 1 < n) ? inventory[i + 1] : 0;
            long long cnt = i + 1;
            long long diff = curr - next;
            long long canSell = cnt * diff;
            if (orders >= canSell) {
                // sell full levels
                long long profit = cnt * (sumN(curr) - sumN(next) + MOD) % MOD;
                ans = (ans + profit) % MOD;
                orders -= canSell;
            } else {
                // partial level
                long long full = orders / cnt;
                long long rem = orders % cnt;
                long long high = curr;
                long long low = curr - full;
                long long profit = cnt * (sumN(high) - sumN(low) + MOD) % MOD;
                profit = (profit + rem * low) % MOD;
                ans = (ans + profit) % MOD;
                orders = 0;
            }
        }
        return ans;
    }
};
