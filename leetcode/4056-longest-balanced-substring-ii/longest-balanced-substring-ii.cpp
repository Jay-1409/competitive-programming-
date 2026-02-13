class Solution {
public:
    
    long long make_key(long long x, long long y, long long z) {
        const long long OFFSET = 1000000; 
        x += OFFSET;
        y += OFFSET;
        z += OFFSET;
        return (x << 42) | (y << 21) | z;
    }

    int longestBalanced(string s) {
        int n = s.size();
        
        unordered_map<long long, vector<int>> mp, mp1, mp2, mp3;        
        
        int a = 0, b = 0, c = 0;
        
        mp[make_key(0,0,0)].push_back(0);
        mp1[make_key(0,b,b)].push_back(0);
        mp2[make_key(0,c,c)].push_back(0);
        mp3[make_key(0,a,a)].push_back(0);
        
        char prev = '1';
        int cnt = 0;
        int best_ans = -1;
        
        for(int i = 0; i < n; ++i) {
            if(prev == s[i]) {
                cnt++;
            } else {
                best_ans = max(best_ans, cnt);
                cnt = 1;
                prev = s[i];
            }
            
            a += (s[i] == 'a');
            b += (s[i] == 'b');
            c += (s[i] == 'c');

            long long key  = make_key(a - b, b - c, a - c);
            long long key1 = make_key(a - c, b, b);
            long long key2 = make_key(a - b, c, c);
            long long key3 = make_key(b - c, a, a);

            mp[key].push_back(i + 1);
            mp1[key1].push_back(i + 1);
            mp2[key2].push_back(i + 1);
            mp3[key3].push_back(i + 1);
        }

        best_ans = max(best_ans, cnt);

        auto resolve = [&](unordered_map<long long, vector<int>> &mp) -> int {
            for(auto &i : mp) {
                if(i.second.size() >= 1) {
                    best_ans = max(best_ans, i.second.back() - i.second.front());
                }
            }
            return best_ans;
        };

        return max({resolve(mp), resolve(mp1), resolve(mp2), resolve(mp3)});
    }
};