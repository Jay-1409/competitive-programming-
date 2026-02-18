class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n & 1;
        int loc = 1;
        while(n > 0) {
            if(prev == ((n >> 1) & 1)) {
                return 0;
            }
            prev = ((n >> 1) & 1);
            n = n >> 1;
        }
        return 1;
    }
};