class Solution {
public:
    int smallestNumber(int n) {
        while(true) {
            bool pos = true;
            bool breaked = false;
            int cnt = 0;
            for(int i = 0; i < 32; ++i) {
                // cout << ((n >> i) & 1) << endl;
                if((n >> i) & 1) {
                    if(breaked)
                        pos = false;
                    cnt++;
                } else {
                    breaked = true;
                }
            }
            if(pos)
                return n;
            n++;
        }
        return -1;
    }
};