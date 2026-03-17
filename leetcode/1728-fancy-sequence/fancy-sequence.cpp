class Fancy {
public:
    static const long long MOD = 1e9 + 7;
    vector<long long> arr;
    long long mul = 1;
    long long add = 0;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    long long modInv(long long x) {
        return modPow(x, MOD - 2);
    }

    Fancy() {}

    void append(int val) {
        long long normalized = (val - add + MOD) % MOD;
        normalized = (normalized * modInv(mul)) % MOD;
        arr.push_back(normalized);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= (int)arr.size()) return -1;
        return (arr[idx] * mul + add) % MOD;
    }
};