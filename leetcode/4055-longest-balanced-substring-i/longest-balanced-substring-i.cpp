class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        vector<vector<int>> pfx(n + 1, vector<int>(26, 0));
        for(int j = 0; j < 26; ++j) {
            pfx[1][j] = (s[0] == 'a' + (j));
        }
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < 26; ++j) {
                pfx[i + 1][j] = pfx[i][j] + (s[i] == ('a' + j));
            }
        }
        int best_ans = 1;
        int prev;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                prev = -1;
                for(int k = 0; k < 26; ++k) {
                    int curr_occ = pfx[j + 1][k] - pfx[i][k];
                    if(curr_occ > 0) {
                        if(prev == -1) {
                            prev = curr_occ;
                        } else if(prev != curr_occ) {
                            goto next;
                        }
                    }
                }
                best_ans = max(best_ans, j - i +1 );
                next:;
            }
        }
        return best_ans;
    }
};
/**
1) we can do prefix sums, on the occurance of lettes, in a 26*n array == 260000
2) then just do a n*n = 1000*1000 = 1e6 ops
3) for each subarary segment use prefix sum to get the occurances of each letter, and for any letter with occurance > 0 it will be counted, and if all such elemented have the same occurance that should be a valid subarray 
**/