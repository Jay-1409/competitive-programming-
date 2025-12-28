class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long method1_cost = (1LL * cost1 * need1) + (1LL * cost2 * need2); 
        long long method2_innitial_cost = 1LL * min(need1, need2) * costBoth;
        long long method2_cost = method2_innitial_cost + (need1 > need2 ? 1LL * (need1 - need2) * cost1 : 1LL * (need2 - need1) * cost2);
        return min({method1_cost, method2_cost, 1LL * max(need1, need2) * costBoth});
    }
};