class Solution {
public:
    int reverseBits(int n) {
        int rev = 0;
        for(int i = 0; i < 32; ++i) {
            if((n >> i) & 1) {
                rev |= (1 << (32 - i - 1));
            }
        }
        return rev;
    }
};