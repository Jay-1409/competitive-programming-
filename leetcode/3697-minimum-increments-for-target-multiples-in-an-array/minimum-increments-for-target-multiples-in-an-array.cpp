class Solution {
public:
    using ll = long long;
    static constexpr ll INF = (ll)4e18;

    ll gcdll(ll a, ll b) {
        while (b) {
            ll t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    ll lcmll(ll a, ll b) {
        if (a == 0 || b == 0) return 0;
        ll g = gcdll(a, b);
        if (a / g > INF / b) return INF; // overflow-safe clamp
        return (a / g) * b;
    }

    ll costToMakeMultiple(ll x, ll l) {
        if (l >= INF) return INF;
        ll rem = x % l;
        if (rem == 0) return 0;
        return l - rem;
    }

    ll solveForPartition(const vector<int>& nums, const vector<ll>& groupLCM) {
        int n = (int)nums.size();
        int k = (int)groupLCM.size();

        if (k > n) return INF;

        vector<ll> dp(1 << k, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            vector<ll> ndp = dp; // skip nums[i]

            for (int mask = 0; mask < (1 << k); mask++) {
                if (dp[mask] >= INF) continue;

                for (int g = 0; g < k; g++) {
                    if (mask & (1 << g)) continue;

                    ll c = costToMakeMultiple(nums[i], groupLCM[g]);
                    if (c >= INF) continue;

                    int nmask = mask | (1 << g);
                    ndp[nmask] = min(ndp[nmask], dp[mask] + c);
                }
            }

            dp.swap(ndp);
        }

        return dp[(1 << k) - 1];
    }

    void generatePartitions(
        const vector<int>& perm,
        int idx,
        vector<ll>& currentGroups,
        const vector<int>& nums,
        ll& answer,
        set<vector<ll>>& seen
    ) {
        int m = (int)perm.size();

        if ((int)currentGroups.size() > (int)nums.size()) return;

        if (idx == m) {
            vector<ll> key = currentGroups;
            sort(key.begin(), key.end());

            if (seen.count(key)) return;
            seen.insert(key);

            answer = min(answer, solveForPartition(nums, key));
            return;
        }

        ll curLCM = 1;
        for (int j = idx; j < m; j++) {
            curLCM = lcmll(curLCM, perm[j]);
            if (curLCM >= INF) break;

            currentGroups.push_back(curLCM);
            generatePartitions(perm, j + 1, currentGroups, nums, answer, seen);
            currentGroups.pop_back();
        }
    }

    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        sort(target.begin(), target.end());

        ll answer = INF;
        vector<ll> currentGroups;
        set<vector<ll>> seen;

        do {
            generatePartitions(target, 0, currentGroups, nums, answer, seen);
        } while (next_permutation(target.begin(), target.end()));

        return (int)answer;
    }
};