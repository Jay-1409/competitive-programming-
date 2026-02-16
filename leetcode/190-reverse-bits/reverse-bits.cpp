class Solution {
public:
    int reverseBits(int n) {
        int rev = 0;
        for(int i = 0; i < 32; ++i) {
            int new_loc = (32 - i - 1);
            if((n >> i) & 1) {
                rev |= (1 << new_loc);
            }
        }
        return rev;
    }
};