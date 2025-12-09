class Solution {
public:
    int totalWaviness(int num1, int num2) {
        auto wavy = [&](int x) -> int {
            auto check = [&](int a, int b, int c) -> bool {
                return ((b > a && b > c) || (b < a && b < c));
            };
            int cnt = 0;
            int prev_1 = -1;
            int prev_2 = -1;
            while(x > 0) {
                if(prev_1 == -1) {
                    prev_1 = x % 10;
                } else if(prev_2 == -1) {
                    prev_2 = x % 10;
                } else {
                    int current = x % 10;
                    if(check(prev_1, prev_2, current)) {
                        cnt++;
                    }
                    prev_1 = prev_2;
                    prev_2 = current;
                }
                x /= 10;
            }
            return cnt;
        };
        int ans = 0;
        while(num1 <= num2) {
            ans += wavy(num1);
            num1++;
        }
        return ans;
    }
};