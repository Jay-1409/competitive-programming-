class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int op = 0;
        if (startValue >= target)
            return startValue - target;
        while (target > startValue) {
            if (target & 1) {
                target++;
                op++;
            } else {
                target /= 2;
                op++;
            }
        }
        return op + (startValue - target);
    }
};
