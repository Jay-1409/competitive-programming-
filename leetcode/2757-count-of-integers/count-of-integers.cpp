class Solution {
public:
    static const int MOD = 1000000007;
    string S;
    int lo, hi;
    long long dp[105][905][2];

    long long dfs(int i, int sum, int tight) {
        if (sum > hi) return 0;
        if (i == S.size()) return (sum >= lo && sum <= hi);
        if (!tight && dp[i][sum][0] != -1) return dp[i][sum][0];
        long long res = 0;
        int lim = tight ? S[i] - '0' : 9;
        for (int d = 0; d <= lim; d++) {
            res = (res + dfs(i + 1, sum + d, tight && d == lim)) % MOD;
        }
        if (!tight) dp[i][sum][0] = res;
        return res;
    }

    string dec(string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == '0') s[i--] = '9';
        if (i >= 0) s[i]--;
        int p = 0;
        while (p + 1 < s.size() && s[p] == '0') p++;
        return s.substr(p);
    }

    long long f(string x) {
        S = x;
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, 1);
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        lo = min_sum;
        hi = max_sum;
        string a = num1;
        string b = num2;
        string a1 = (a == "0" ? "0" : dec(a));
        long long ans = (f(b) - f(a1)) % MOD;
        if (ans < 0) ans += MOD;
        return ans;
    }
};
