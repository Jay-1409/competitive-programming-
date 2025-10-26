class Solution {
public:
    int findIntegers(int n) {
        auto dfs = [&](int num, auto && self) -> int {
            if(num > n)
                return 0;
            if(num & 1) {
                int going_next = (num << 1);
                return 1 + self(going_next, self);
            } else {
                int going_next_first = (num << 1);
                int going_next_second = (num << 1) | 1;
                return 1 + self(going_next_first, self) + self(going_next_second, self);
            }
        };
        return 1 + dfs(1, dfs);
    }
};
// NOTES

/**

**/
        