class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int cnt = 0;
        long long mine = LLONG_MAX;
        long long sum = 0;
        for(auto &i : matrix) {
            for(auto &j : i) {
                if(j < 0) 
                    cnt++;
                sum += abs(j);
                mine = min(mine, 1LL * abs(j));
            }
        }
        //cout << mine << endl;
        if(cnt & 1) {
            sum -= 2 * mine;
        } 
        return sum;
    }
};