class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        int weeks = n / 7;
        int days = n % 7;
        for (int w = 0; w < weeks; ++w) {
            total += (7 * (w + 1)) + 21; 
        }
        for (int d = 0; d < days; ++d) {
            total += (weeks + 1 + d);
        }
        return total;
    }
};
