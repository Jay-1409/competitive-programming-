class Solution {
public:
    int numSub(string s) {
        int ans = 0;
        const long long MOD = 1e9 + 7;
        int l;
        for(int r = 0; r < (int)s.size(); ++r) {
            bool ok = false;
            l = r;
            while(r < (int)s.size() && s[r] == '1') {
                r++;
                ok = true;
            }
            if(ok) {
                //sz >= 2
                long long diff = r - l;
                cout << diff << endl;
                long long adds = diff * (diff + 1) / 2;
                ans = (ans + adds) % MOD;
            }
        }
        return ans;
    }
};