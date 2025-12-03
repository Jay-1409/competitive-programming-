class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int, int> yy;
        const long long MOD = 1e9 + 7;
        for(auto &i : points) {
            yy[i[1]]++;
        }
        long long delta = 0;
        long long cnt = 0;
        for(auto &i : yy) {
            long long a = ((1LL * i.second) * (i.second - 1) / 2) % MOD;
            if(a > 0)
                cnt = (cnt + a) % MOD;
            long long r = a;
            if(r > 0)
                delta  = (delta + (r) * (r - 1) / 2 % MOD) % MOD;
                // count combinatiosn that could be formed on the same horizontal
        }
        long long ans = cnt * (cnt - 1) / 2 % MOD;
        // you have lines, now you connect them
        return (ans - delta + MOD) % MOD;
        // remove the combinatisn that were formed in the same horzontal
    }
};