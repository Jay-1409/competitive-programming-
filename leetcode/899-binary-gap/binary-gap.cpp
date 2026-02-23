class Solution {
public:
    int binaryGap(int n) {
        int gap = 0;
        int max_gap = 0;
        int prev = 0;
        for(int i = 0; i < 32; ++i) {
            if((n >> i) & 1 && prev) {
                max_gap = max(max_gap, gap + 1);
                gap = 0;
            } else if((n >> i) & 1) {
                prev = 1;
                gap = 0;
            } else {
                gap++;
            }
        }
        return max_gap;
    }
};