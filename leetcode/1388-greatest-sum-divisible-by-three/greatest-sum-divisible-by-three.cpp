class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int dp0 = 0, dp1 = INT_MIN, dp2 = INT_MIN;

        for (int num : nums) {
            int r = num % 3;

            int a = dp0, b = dp1, c = dp2;

            if (r == 0) {
                dp0 = a + num;
                dp1 = (b == INT_MIN ? INT_MIN : b + num);
                dp2 = (c == INT_MIN ? INT_MIN : c + num);

            } else if (r == 1) {
                dp0 = max(a, c + num);
                dp1 = max(b, a + num);
                dp2 = max(c, b + num);

            } else { // r == 2
                dp0 = max(a, b + num);
                dp1 = max(b, c + num);
                dp2 = max(c, a + num);
            }
        }

        return dp0;
    }
};

/**
we can have different mods when to comes to 3
- mainly 0, 1 and 2

- keep the track of the previous 0 1 and 2th mod

- so if your current numbers mod is 1 you can pair it with the previous 2 and like that
- also update the other mod values like this 

if the current mod is 1
- then if you pair it up with the previous mod 1 the it becomes the current mod2-
- if you pair it with previous mod0 then it becomes current mod1

if the current mod is 2
- then you pair it with the previous mod 2 it becomes the current mod1
- if you pair it with the previous mod 0, it becomes the current mod2

same goes for when the current mod is 3

**/