class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i = 1; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                int sqsum = sqrt(i*i + j*j);
                if(sqsum <= n && ((i*i + j*j) == sqsum*sqsum)) {
                    // cout << i << " " << j << " " << sqsum << endl;
                    cnt++;
                }
            }
        }
        return cnt*2;
    }
};